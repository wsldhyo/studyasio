#include "../include/server.hpp"
#include <asio/buffer.hpp>
#include <asio/error_code.hpp>
#include <asio/ip/tcp.hpp>
#include <asio/system_error.hpp>
#include <asio/write.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <cstddef>
#include <cstring>
#include <functional>
#include <iostream>
#include <memory>

MsgNode::MsgNode(short msg_len) : total_len(msg_len + MSG_HEAD_LEN), cur_len() {
  data = new char[total_len + 1];       // 多申请一个字节放\0
  memcpy(data, &msg_len, MSG_HEAD_LEN); // 将消息长度放入前两个字节
  data[total_len] = '\0';
}
MsgNode::MsgNode(char *msg, int len) : MsgNode(len) {
  // 前两个字节放消息长度了, 要偏移两字节
  memcpy(data + MSG_HEAD_LEN, msg, len);
}
MsgNode::~MsgNode() { delete[] data; }

void MsgNode::clear() {
  memset(data, 0, total_len);
  cur_len = 0;
}
CSession::CSession(asio::io_context &ioc, CServer *server)
    : sock_(ioc), server_(server) {

  boost::uuids::uuid a_uuid = boost::uuids::random_generator()();
  uuid_ = boost::uuids::to_string(a_uuid);
}

std::string &CSession::get_uuid() { return uuid_; }

asio::ip::tcp::socket &CSession::socket() { return sock_; }

void CSession::start() {
  memset(data_, 0, MAX_LENGTH);
  // 不能使用shared_ptr<CSession>(this)、make_shared等方式创建智能指针，多次调用start()会导致多个智能指针管理同一快内存，引用计数不同步
  // 几不能使用相同的裸指针创建多个不同的智能指针
  // shared_from_this保证了生成的多个智能指针的引用计数同步
  auto sp_self = shared_from_this();
  sock_.async_read_some(asio::buffer(data_, MAX_LENGTH),
                        std::bind(&CSession::handle_read_callback_, this,
                                  std::placeholders::_1, std::placeholders::_2,
                                  sp_self));
}
void CSession::close() {
  sock_.close();
  b_close_ = true;
}

void CSession::send(char *msg, int max_length) {
  // 不能保证发送的接口和回调函数的接口在一个线程，所以要增加一个锁保证发送队列安全性
  std::lock_guard<std::mutex> lock(send_lock_);
  int send_que_size = send_que_.size(); 
  if (send_que_size > MAX_SEND_QUE) {
  
  }
  bool pending =
      false; // true表示当前发送队列里有数据，即send上次调用的传递数据还未发送完毕
  if (send_que_.size() > 0) {
    pending = true;
  }
  send_que_.push(std::make_shared<MsgNode>(msg, max_length));
  // pendind为false，则说明有数据需要发送，不能直接return，需要提交异步写操作
  if (pending) {
    return;
  }
  asio::async_write(sock_, asio::buffer(msg, max_length),
                    std::bind(&CSession::handle_write_callback_, this,
                              std::placeholders::_1, shared_from_this()));
}

void CSession::handle_write_callback_(asio::error_code const &ec,
                                      std::shared_ptr<CSession> sp_self) {
  if (!ec) {
    std::lock_guard<std::mutex> lock(send_lock_);
    send_que_.pop(); // ec不为0，前次调用发送完队首元素，所以去掉队首元素
    if (!send_que_.empty()) {
      // 队列不空，则继续发送
      auto &msgnode = send_que_.front();
      asio::async_write(sock_, asio::buffer(msgnode->data, msgnode->total_len),
                        std::bind(&CSession::handle_write_callback_, this,
                                  std::placeholders::_1, sp_self));
    }
  } else {
    std::cout << "handle write failed, error is " << ec.message() << std::endl;
    close();
    server_->remove_session(uuid_);
  }
}

void CSession::handle_read_callback_(const asio::error_code &ec,
                                     size_t bytes_transferred,
                                     std::shared_ptr<CSession> _self_shared) {
  if (!ec) {
    // copy_len表示已经处理的字符数，bytes_transferred表示未处理的数据
    int copy_len = 0;
    while (bytes_transferred > 0) {
      // 处理头部消息
      if (!b_head_parse_) {
        // 未处理数据长度与头部当前长度不足MSG_HEAD_LEN，说明头部消息没有接受完毕
        if (bytes_transferred + recv_head_node_->cur_len < MSG_HEAD_LEN) {
          // 将byte_transferred的全部内容拷贝到头部节点
          // copy_len表示已经拷贝的长度，所以要从data_+copy_len开始拷贝
          memcpy(recv_head_node_->data + recv_head_node_->cur_len + copy_len,
                 data_ + copy_len, bytes_transferred);
          recv_head_node_->cur_len += bytes_transferred;
          memset(data_, 0, MAX_LENGTH);
          // 挂起读取操作，监听对方的写事件
          sock_.async_read_some(asio::buffer(data_, MAX_LENGTH),
                                std::bind(&CSession::handle_read_callback_,
                                          this, std::placeholders::_1,
                                          std::placeholders::_2, _self_shared));
          return;
        }
        // 收到的数据长度大于头部长度，包含数据域
        // 那么从这些长度里取出头部长度，并将数据域数据取出
        int head_remain = MSG_HEAD_LEN - recv_head_node_->cur_len;
        memcpy(recv_head_node_->data + recv_head_node_->cur_len,
               data_ + copy_len, head_remain);

        // 头部节点数据拷贝完成
        copy_len += head_remain;
        bytes_transferred -= head_remain;

        // 从头部节点取出数据长度
        short data_len{0};
        memcpy(&data_len, recv_head_node_->data, MSG_HEAD_LEN);
        std::cout << "data len is " << data_len << std::endl;

        // 数据长度非法
        if (data_len > MAX_LENGTH) {
          std::cout << "invalid data len is " << data_len << std::endl;
          // 直接断开连接
          close();
          server_->remove_session(uuid_);
          return;
        }

        // 创建消息节点, 用于接收消息
        recv_msg_node_ = std::make_shared<MsgNode>(data_len);
        // 消息未接收全，先保存一部分
        if (bytes_transferred < data_len) {
          memcpy(recv_msg_node_->data + recv_msg_node_->cur_len,
                 data_ + copy_len, bytes_transferred);
          memset(data_, 0, MAX_LENGTH);
          // 挂起读处理，监听对方的写事件
          sock_.async_read_some(asio::buffer(data_, MAX_LENGTH),
                                std::bind(&::CSession::handle_read_callback_,
                                          this, std::placeholders::_1,
                                          std::placeholders::_2, _self_shared));
          b_head_parse_ = true;
          return;
        }

        // 接收到的大于等于数据长度（TCP流中可能有多个包）
        // 需要拷贝完当前包数据，然后处理下一个包的头部

        memcpy(recv_msg_node_->data + recv_msg_node_->cur_len, data_ + copy_len,
               data_len);
        recv_msg_node_->cur_len += data_len;
        copy_len += data_len;
        bytes_transferred -= data_len;
        recv_msg_node_->data[recv_msg_node_->total_len] = '\0';
        std::cout << "receive data is " << recv_msg_node_->data << std::endl;

        // 此处可以调用send发送给客户端测试
        send(recv_msg_node_->data, recv_msg_node_->total_len);

        // 继续轮询剩余未处理数据
        b_head_parse_ = false;
        recv_head_node_->clear();

        // 流中没有数据，监听读事件
        if (bytes_transferred <= 0) {

          ::memset(data_, 0, MAX_LENGTH);
          sock_.async_read_some(asio::buffer(data_, MAX_LENGTH),
                                std::bind(&CSession::handle_read_callback_,
                                          this, std::placeholders::_1,
                                          std::placeholders::_2, _self_shared));
          return;
        }
        // 流中还有数据，继续处理下一头部信息
        continue;
      }

      // 已经处理完头部，处理上次未接受完的消息数据
      // 接收的数据仍不足剩余未处理的
      int remain_msg = recv_msg_node_->total_len - recv_msg_node_->cur_len;

      // 未处理长度小于消息长度，说明消息尚未接收完整
      if (bytes_transferred < remain_msg) {
        memcpy(recv_msg_node_->data + recv_msg_node_->cur_len, data_ + copy_len,
               bytes_transferred);
        recv_msg_node_->cur_len += bytes_transferred;
        ::memset(data_, 0, MAX_LENGTH);
        sock_.async_read_some(asio::buffer(data_, MAX_LENGTH),
                              std::bind(&CSession::handle_read_callback_, this,
                                        std::placeholders::_1,
                                        std::placeholders::_2, _self_shared));
        return;
      }

      // 未处理长度大于等于消息长度，则可能有多个包
      memcpy(recv_msg_node_->data + recv_msg_node_->cur_len, data_ + copy_len,
             remain_msg);
      recv_msg_node_->cur_len += remain_msg;
      bytes_transferred -= remain_msg;
      copy_len += remain_msg;
      recv_msg_node_->data[recv_msg_node_->total_len] = '\0';
      std::cout << "receive data is " << recv_msg_node_->data << std::endl;
      // 此处可以调用Send发送测试
      send(recv_msg_node_->data, recv_msg_node_->total_len);

      // 继续轮询剩余未处理数据
      b_head_parse_ = false;
      recv_head_node_->clear();

      // 包处理完毕
      if (bytes_transferred <= 0) {
        ::memset(data_, 0, MAX_LENGTH);
        sock_.async_read_some(asio::buffer(data_, MAX_LENGTH),
                              std::bind(&CSession::handle_read_callback_, this,
                                        std::placeholders::_1,
                                        std::placeholders::_2, _self_shared));
        return;
      }

      // 有多个包，继续处理
      continue;
    }
  } else {
    std::cout << "handle read failed, error is " << ec.message() << std::endl;
    close();
    server_->remove_session(uuid_);
  }
}
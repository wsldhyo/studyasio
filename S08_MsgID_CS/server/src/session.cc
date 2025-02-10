#include <asio/buffer.hpp>
#include <asio/detail/socket_ops.hpp>
#include <asio/read.hpp>
#include <sys/socket.h>

#include <cstring>
#include <functional>
#include <iostream>
#include <memory>
#include <ostream>

#include "../include/server.hpp"
#include "../../common/msgnode.hpp"
#include "../../common/const.h"
CSession::CSession(asio::io_context &io_context, CServer *server)
    : socket_(io_context), server_(server), b_close_(false)
      {
  boost::uuids::uuid a_uuid = boost::uuids::random_generator()();
  uuid_ = boost::uuids::to_string(a_uuid);
  recv_head_node_ = std::make_shared<MsgNode>(MSG_ID_LEN + MSG_DATA_LEN);
}
CSession::~CSession() { std::cout << "~CSession destruct" << std::endl; }

tcp::socket &CSession::get_socket() { return socket_; }

std::string &CSession::get_uuid() { return uuid_; }

void CSession::start() {
  recv_head_node_->clear();
  asio::async_read(socket_, asio::buffer(recv_head_node_->data, MSG_DATA_LEN + MSG_ID_LEN), 
  std::bind(&CSession::read_head_callback_, this, std::placeholders::_1, std::placeholders::_2, shared_self()));
}

void CSession::send(char *msg, short max_length, short msg_id) {
  std::lock_guard<std::mutex> lock(send_lock_);
  int send_que_size = send_que_.size();
  if (send_que_size > MAX_SENDQUE) {
    std::cout << "session: " << uuid_ << " send que fulled, size is "
              << MAX_SENDQUE << std::endl;
    return;
  }

  send_que_.push(std::make_shared<SendNode>(msg, max_length, msg_id));
  if (send_que_size > 0) {
    return;
  }
  auto &msgnode = send_que_.front();
  asio::async_write(socket_, asio::buffer(msgnode->data, msgnode->total_len),
                    std::bind(&CSession::write_callback_, this,
                              std::placeholders::_1, shared_self()));
}

void CSession::close() {
  socket_.close();
  b_close_ = true;
}

std::shared_ptr<CSession> CSession::shared_self() { return shared_from_this(); }

void CSession::write_callback_(const asio::error_code &error,
                                      std::shared_ptr<CSession> shared_self) {

  if (!error) {
    std::lock_guard<std::mutex> lock(send_lock_);
    std::cout << "send data " << send_que_.front()->data + MSG_ID_LEN + MSG_DATA_LEN
              << std::endl;
    send_que_.pop();
    if (!send_que_.empty()) {
      auto &msgnode = send_que_.front();
      asio::async_write(socket_,
                        asio::buffer(msgnode->data, msgnode->total_len),
                        std::bind(&CSession::write_callback_, this,
                                  std::placeholders::_1, shared_self));
    }
  } else {
    std::cout << "handle write failed, error is " << error.message()
              << std::endl;
    close();
    server_->remove_session(uuid_);
  }
}

void CSession::read_head_callback_(const asio::error_code &error,
                                   size_t bytes_transferred,
                                   std::shared_ptr<CSession> shared_self) {
  if (!error) {
    if (bytes_transferred < MSG_ID_LEN + MSG_DATA_LEN ) {
      std::cout << "read head length error\n";
      close();
      server_->remove_session(uuid_);
      return;
    }
    short data_len = 0;
    short data_id = 0;
    memcpy(&data_id, recv_head_node_->data,  MSG_ID_LEN);
    memcpy(&data_len, recv_head_node_->data + MSG_ID_LEN, MSG_DATA_LEN);
    data_id = asio::detail::socket_ops::network_to_host_short(data_id);
    data_len = asio::detail::socket_ops::network_to_host_short(data_len);

    std::cout << "recv data id is " << data_id << " length is " << data_len << std::endl;

    if (data_len > MAX_LENGTH) {
      std::cout << "invalid data length" << std::endl;
      server_->remove_session(uuid_);
    }

    recv_msg_node_ = std::make_shared<RecvNode>(data_len, data_id);
    asio::async_read(
        socket_, asio::buffer(recv_msg_node_->data, data_len),
        std::bind(&CSession::read_msg_callback_, this, std::placeholders::_1,
                  std::placeholders::_2, shared_self));
  } else {
    std::cout << "read head info failed, error is " << error.message() << std::endl;
    close();
    server_->remove_session(uuid_);
  }
}

void CSession::read_msg_callback_(const asio::error_code &error,
                                  size_t bytes_transferred,
                                  std::shared_ptr<CSession> shared_self) {
  if (!error) {
     recv_msg_node_->data[recv_msg_node_->total_len] = '\0';
     std::cout << "recv msg is " << recv_msg_node_->data << std::endl;
     // 回传给客户端
     send(recv_msg_node_->data, recv_msg_node_->total_len, recv_msg_node_->msg_id);

     // 挂起读头部事件，准备读取下一消息
     recv_head_node_->clear();
     asio::async_read(socket_, asio::buffer(recv_head_node_->data, MSG_ID_LEN + MSG_DATA_LEN),
      std::bind(&CSession::read_head_callback_, this, std::placeholders::_1, std::placeholders::_2, shared_self));   
  } else {
    std::cout << "read head info failed, error is " << error.message() << std::endl;
    close();
    server_->remove_session(uuid_);
  }
}
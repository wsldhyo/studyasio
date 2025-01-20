#ifndef SESSION_HPP
#define SESSION_HPP

#include <asio/error_code.hpp>
#include <asio/io_context.hpp>
#include <asio/ip/tcp.hpp>
#include <asio/system_error.hpp>
#include <cstddef>
#include <cstring>
#include <memory>
#include <mutex>
#include <queue>

inline constexpr short MSG_HEAD_LEN{2};
inline constexpr int MAX_LENGTH{2 * 1024};
inline constexpr int MAX_SEND_QUE{1000};
inline constexpr int MAX_RECV_QUE{1000};

/// 以tlv格式设计MsgNode，方便应用层对TCP流数据切包
class MsgNode {
  friend class CSession;

public:
  explicit MsgNode(short msg_len);
  MsgNode(char *msg, int len);
  ~MsgNode();
  /// 清除data里的数据，长度置0, 以待下次使用
  // 实际上并不需要清空，拷贝数据后将最后一个字节置\0即可
  void clear();

private:
  int cur_len; //
  int total_len;
  char *data;
};
class CServer;
class CSession : public std::enable_shared_from_this<CSession> {
public:
  using sp_msg_t = std::shared_ptr<MsgNode>;
  using sp_Session_t = std::shared_ptr<CSession>;

public:
  CSession(asio::io_context &ioc, CServer *server);

  asio::ip::tcp::socket &socket();
  std::string &get_uuid();
  void start();
  void send(char *msg, int max_length);
  // 关闭socket
  void close();
private:
  void handle_read_callback_(asio::error_code const &ec,
                             std::size_t bytes_tranferred,
                             sp_Session_t sp_self);
  void handle_write_callback_(asio::error_code const &ec, sp_Session_t sp_self);

private:
  CServer *server_;
  asio::ip::tcp::socket sock_;
  std::string uuid_;
  char data_[MAX_LENGTH];
  
  std::queue<sp_msg_t> send_que_; // 异步发送队列
  std::mutex send_lock_;

  bool b_close_;
  bool b_head_parse_;       // 头部消息是否发送完毕
  sp_msg_t recv_msg_node_;  // 收到的头部消息结构
  sp_msg_t recv_head_node_; // 收到的消息结构
};
#endif
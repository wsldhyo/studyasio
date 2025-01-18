#ifndef SESSION_HPP
#define SESSION_HPP

#include <asio/io_context.hpp>
#include <asio/ip/tcp.hpp>
#include <cstddef>
#include <memory>
//class SessionErr {
//public:
//  explicit SessionErr(asio::io_context &ioc);
//
//  asio::ip::tcp::socket &socket();
//
//  void start();
//
//private:
//  void handle_read_(asio::error_code const &ec, std::size_t bytes_tranferred);
//  void handle_write_(asio::error_code const &ec);
//
//private:
//  asio::ip::tcp::socket sock_;
//  enum { MAX_LENGTH = 1024 };
//  char data_[MAX_LENGTH];
//};

class CServer;
class CSession : public std::enable_shared_from_this<CSession>{
public:
  CSession(asio::io_context &ioc, CServer *server);

  asio::ip::tcp::socket &socket();
  std::string &get_uuid();
  void start();
  std::shared_ptr<CSession> get_spthis();
private:
  void handle_read_(asio::error_code const &ec, std::size_t bytes_tranferred,
                    std::shared_ptr<CSession> sp_self);
  void handle_write_(asio::error_code const &ec,
                     std::shared_ptr<CSession> sp_self);

private:
  asio::ip::tcp::socket sock_;
  enum { MAX_LENGTH = 1024 };
  char data_[MAX_LENGTH];
  CServer *server_;
  std::string uuid_;
};
#endif
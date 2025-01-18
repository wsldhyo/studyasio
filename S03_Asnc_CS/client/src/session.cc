#include "../include/server.hpp"
#include <asio/ip/tcp.hpp>
#include <asio/write.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <cstddef>
#include <cstring>
#include <functional>
#include <iostream>

//SessionErr::SessionErr(asio::io_context &ioc) : sock_(ioc) {}
//
//asio::ip::tcp::socket &SessionErr::socket() { return sock_; }
//
//void SessionErr::start() {
//  memset(data_, 0, MAX_LENGTH);
//  sock_.async_read_some(asio::buffer(data_, MAX_LENGTH),
//                        std::bind(&SessionErr::handle_read_, this,
//                                  std::placeholders::_1,
//                                  std::placeholders::_2));
//}
//void SessionErr::handle_read_(asio::error_code const &ec,
//                              std::size_t bytes_tranferred) {
//  if (!ec) {
//    std::cout << "server receive data is " << data_ << std::endl;
//    asio::async_write(
//        sock_, asio::buffer(data_, bytes_tranferred),
//        std::bind(&SessionErr::handle_write_, this, std::placeholders::_1));
//
//  } else {
//    std::cout << "read error" << std::endl;
//    delete this;
//  }
//}
//void SessionErr::handle_write_(asio::error_code const &ec) {
//
//  if (!ec) {
//    memset(data_, 0, MAX_LENGTH);
//    sock_.async_read_some(asio::buffer(data_, MAX_LENGTH),
//                          std::bind(&SessionErr::handle_read_, this,
//                                    std::placeholders::_1,
//                                    std::placeholders::_2));
//
//  } else {
//    std::cout << "write error" << std::endl;
//    delete this;
//  }
//}


CSession::CSession(asio::io_context &ioc, CServer *server)
    : sock_(ioc), server_(server) {

  boost::uuids::uuid a_uuid = boost::uuids::random_generator()();
  uuid_ = boost::uuids::to_string(a_uuid);
}

std::string &CSession::get_uuid() { return uuid_; }

  std::shared_ptr<CSession> CSession::get_spthis(){
    return shared_from_this();
  }
asio::ip::tcp::socket& CSession::socket()
{
  return sock_;
}

void CSession::start()
{
  memset(data_, 0, MAX_LENGTH);
  // 不能使用shared_ptr<CSession>(this)、make_shared等方式创建智能指针，多次调用start()会导致多个智能指针管理同一快内存，引用计数不同步
  // 几不能使用相同的裸指针创建多个不同的智能指针
  // shared_from_this保证了生成的多个智能指针的引用计数同步
  auto sp_self = shared_from_this();
  sock_.async_read_some(asio::buffer(data_, MAX_LENGTH),
  std::bind(&CSession::handle_read_, this, std::placeholders::_1, std::placeholders::_2, sp_self));
}


void CSession::handle_read_(asio::error_code const &ec,
                              std::size_t bytes_tranferred, std::shared_ptr<CSession> sp_self) {
  if (!ec) {
    std::cout << "server receive data is " << data_ << std::endl;
    asio::async_write(
        sock_, asio::buffer(data_, bytes_tranferred),
        std::bind(&CSession::handle_write_, this, std::placeholders::_1, sp_self));

  } else {
    std::cout << "read error" << std::endl;
    //delete this;
    server_->remove_session(uuid_);
  }
}
void CSession::handle_write_(asio::error_code const &ec, std::shared_ptr<CSession> sp_self) {

  if (!ec) {
    memset(data_, 0, MAX_LENGTH);
    sock_.async_read_some(asio::buffer(data_, MAX_LENGTH),
                          std::bind(&CSession::handle_read_, this,
                                    std::placeholders::_1,
                                    std::placeholders::_2,
                                    sp_self));

  } else {
    std::cout << "write error" << std::endl;
    //delete this;
    server_->remove_session(uuid_);
  }
}

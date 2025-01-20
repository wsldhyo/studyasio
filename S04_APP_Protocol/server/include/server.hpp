#ifndef SERVER_HPP
#define SERVER_HPP
#include "session.hpp"
#include <string>
#include <map>
#include <memory>

class CServer{
public:
    CServer(asio::io_context& ioc, short port_num);
    void remove_session(std::string& uuid); 
private:
    void start_accept();
    void handle_accept(std::shared_ptr<CSession> new_session, asio::error_code const& ec);
private:
    asio::io_context& ioc_;
    asio::ip::tcp::acceptor acceptor_;
    std::map<std::string, std::shared_ptr<CSession>> sessions_;
};
#endif
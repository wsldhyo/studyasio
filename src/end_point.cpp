#include <asio/io_context.hpp>
#include <asio/ip/address_v6.hpp>
#include <asio/ip/tcp.hpp>
#include <string>
#include <iostream>

#include <asio/error_code.hpp>
#include <asio/ip/address.hpp>
#include "end_point.hpp"
inline int client_end_point(){
    std::string raw_ip_address = "127.4.8.1";
    port_t port_num = 3333;
    asio::error_code ec;
    // make_address替代了boost版中的from_string函数
    asio::ip::address ip_address = asio::ip::make_address(raw_ip_address);
    if (ec.value() != 0) {
        std::cout << "Failed to parsed the IP address. Error Code: " << ec.value()
            << " Message: " << ec.message() << std::endl; 
        return ec.value();
    }
    asio::ip::tcp::endpoint ep(ip_address, port_num);
    return 0;
}


inline int server_end_point(){
    port_t port_num = 3333;
    // 任何地址？？？
    asio::ip::address ip_address = asio::ip::address_v6::any();
    asio::ip::tcp::endpoint ep(ip_address, port_num);
    return 0;    
}

inline int create_tcp_socket(){
    asio::io_context ioc;
    asio::ip::tcp protocol = asio::ip::tcp::v4();
    asio::ip::tcp::socket sock(ioc);
    asio::error_code ec;
    sock.open(protocol, ec);
    if (ec.value() != 0) {
        std::cout << "Failed to open the socket! Error code:" << ec.value() 
                    << " Message: " << ec.message() << std::endl;
        return ec.value();
    }
    return 0;

    // 新版asio 可以更简单的打开sock》》
}
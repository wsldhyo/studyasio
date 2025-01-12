#ifndef END_POINT_HPP
#define END_POINT_HPP

using port_t = unsigned short;
// 客户端通信端口
inline int client_end_point();

// 服务端通信端口
inline int server_end_point();

inline int create_tcp_socket();
#endif

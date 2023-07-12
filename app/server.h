#pragma once
#include <boost/asio.hpp>
#include "chat_session.h"
#include <mutex>

using boost::asio::ip::tcp;
class Server{

public:
    Server(boost::asio::io_context & io_context, uint16_t port)
    : m_acceptor(io_context, tcp::endpoint(tcp::v4(), port)),
    m_socket(io_context){
        acceptConnections();
    }


private:
    void acceptConnections();
    tcp::acceptor m_acceptor;
    tcp::socket m_socket;
    std::deque<std::shared_ptr<ChatSession>> m_sessions;
};

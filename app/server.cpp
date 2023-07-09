
#include "server.h"

void Server::acceptConnections() {
    m_acceptor.async_accept(m_socket,
                            [this](boost::system::error_code ec){
        if(!ec){
            std::make_shared<ChatSession>(std::move(m_socket), m_sessions)->start();
        }
        acceptConnections();
    });
}



#include "server.h"

void Server::acceptConnections() {
    m_acceptor.async_accept(m_socket,
                            [this](boost::system::error_code ec){
        if(!ec){
            std::shared_ptr<ChatSession> chat_session = std::make_shared<ChatSession>(std::move(m_socket), m_sessions);
            {
                m_sessions.push_back(chat_session);
            }
            chat_session->start();
        }
        acceptConnections();
    });
}


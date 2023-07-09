
#include "chat_session.h"

void ChatSession::start() {
    m_sessions.push_back(shared_from_this());
    write("Welocome, provide a username to use this chat\n");
    readUsername();
}

void ChatSession::readUsername() {
    boost::asio::async_read_until(m_client_socket, m_inputBuffer, '\n',
                                  [this, self=shared_from_this()](boost::system::error_code ec, std::size_t size){
                                      if(!ec){
                                          m_username = readBufferToString();
                                          broadcast(m_username + " joined to the chat!\n");
                                          startReading();
                                      }else{
                                          closeSession();
                                      }
                                  });
}

void ChatSession::startReading() {
    boost::asio::async_read_until(m_client_socket, m_inputBuffer, '\n',
                                  [this, self = shared_from_this()](boost::system::error_code ec, std::size_t size){
                                      if(!ec){
                                          std::string msg = readBufferToString();
                                          broadcast(m_username + ": " + msg);
                                          startReading();
                                      }else{
                                          closeSession();
                                      }
                                  });
}

void ChatSession::broadcast(const std::string &msg) {
    for(const auto& session: m_sessions){
        if(session != shared_from_this())
            session->write(msg);
    }
}

std::string ChatSession::readBufferToString(){
    std::istream input(&m_inputBuffer);
    std::string msg;
    std::getline(input, msg);
    return msg;
}

void ChatSession::write(const std::string &msg) {
    boost::asio::async_write(m_client_socket, boost::asio::buffer(msg),
                             [this, self=shared_from_this()](boost::system::error_code ec, std::size_t size){
                                 if(ec){
                                     closeSession();
                                 }
                             }
    );
}

void ChatSession::closeSession(){
    auto self = shared_from_this();
    m_sessions.erase(std::remove(m_sessions.begin(), m_sessions.end(), self));
    m_client_socket.close();
}



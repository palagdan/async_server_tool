#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;


class ChatSession : public std::enable_shared_from_this<ChatSession>{

public:
    ChatSession(tcp::socket socket, std::deque<std::shared_ptr<ChatSession>> & sessions)
    : m_client_socket(std::move(socket)), m_sessions(sessions), m_inputBuffer(){}

    void start();

private:

    void readUsername();
    void startReading();
    void broadcast(const std::string & msg);
    std::string readBufferToString();
    void write(const std::string & msg);
    void closeSession();

    tcp::socket m_client_socket;
    std::string m_username;
    std::deque<std::shared_ptr<ChatSession>> & m_sessions;
    boost::asio::streambuf  m_inputBuffer;
};


#pragma once
#include <vector>
#include "server.h"
#include <cstdint>
#include <thread>
#include "server.h"
class Application{

public:

    Application() : m_amount_servers(0) {}

    void createNewServer(const Server & server){

    }

private:
    struct ServerInfo{
        Server m_server;
        std::thread::id m_thread_id;
    };
    std::vector<ServerInfo> m_servers;
    uint16_t m_amount_servers;
};

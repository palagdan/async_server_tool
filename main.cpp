#include <iostream>
#include <vector>
#include "app/server.h"
#include <thread>
#include "utilities/tool.h"
using boost::asio::ip::tcp;



#define NUM_THREADS 4
int main(int argc, char ** argv) {
    std::vector<std::string> args(argv + 1, argv + argc);
    // Iterate through command-line arguments
    int port = 0;
    for (auto it = args.begin(); it != args.end(); ++it) {
        if (*it == "--help" && std::next(it) != args.end()) {
            Tool::displayHelpMessage(*std::next(it));
        }else if (*it == "--port" && std::next(it) != args.end()){
                port = std::stoi(*std::next(it));
        }else{

        }
    }
    boost::asio::io_context io_context;
    Server server(io_context, port);
    std::vector<std::thread> threads;
    for(int i = 0; i < NUM_THREADS; ++i){
        threads.emplace_back([&io_context]{
            io_context.run();
        });
    }

    for(int i = 0; i < NUM_THREADS; ++i){
        threads[i].join();
    }
    return 0;
}

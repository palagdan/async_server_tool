#include <iostream>
#include <vector>
#include "app/server.h"
int main(int argc, char ** argv) {

//    std::vector<std::string> args(argv + 1, argv + argc);
//
//    // Iterate through command-line arguments
//    for (const auto & arg : args) {
//        // Check for specific flags
//        if(arg == "--help"){
//            // tools class
//        }else{
//
//        }
//    }

    try {
        boost::asio::io_context io_context;
        Server server(io_context, 12345);
        io_context.run();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}

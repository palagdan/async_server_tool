cmake_minimum_required(VERSION 3.22)
project(server_chats)

set(CMAKE_CXX_STANDARD 17)

add_executable(server_chats main.cpp utilities/tool.h utilities/tool.cpp utilities/config_parser.h utilities/ini_parser.cpp utilities/ini_parser.h app/application.cpp app/application.h app/server.cpp app/server.h app/chat_session.h app/chat_session.cpp logging/logging.h logging/file_logging.h logging/console_logging.h logging/console_logging.cpp logging/file_logging.cpp)

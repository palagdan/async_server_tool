# Asynchronous Chat Server with Threads

* [Project Description](#Project-Description)
* [Features](#features)
* [Prerequisites](#prerequisites)

## Project Description
This is an asynchronous chat server implementation that
allows multiple clients to connect and exchange messages 
in real-time. The server is built using asynchronous 
I/O and utilizes threads for concurrent handling of 
client connections.

## Features
- Asynchronous I/O: The server utilizes asynchronous I/O 
operations to handle multiple client connections efficiently.
- Multiple Client Support: The server can handle multiple 
client connections simultaneously.
- Real-time Messaging: Clients can exchange messages in
real-time, enabling interactive chat functionality.
- Threaded Architecture: The server uses threads to handle
concurrent client connections, allowing for better scalability and responsiveness.
- Simple Protocol: The server implements a simple chat 
protocol for communication between the clients and the server.

## Prerequisites
- C++ Compiler: The server is implemented in C++ and requires
a compatible C++ compiler.
- Boost Library: The Boost.Asio library is used for 
asynchronous I/O operations. Make sure to have the Boost library installed and configured.
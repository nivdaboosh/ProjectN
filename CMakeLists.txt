cmake_minimum_required(VERSION 3.16.3)
project(Server)
project(Client)

set(CMAKE_CXX_STANDARD 11)

add_executable(Server server/main.cpp server/Knn.cpp server/Knn.h Iris.h
        Iris.cpp server/UDPServer.h server/UDPServer.cpp server/TCPServer.cpp server/TCPServer.h)
add_executable(Client client/main.cpp client/UDPClient.cpp client/UDPClient.h client/TCPClient.cpp
        client/TCPClient.h Iris.h Iris.cpp)
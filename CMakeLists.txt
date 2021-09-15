cmake_minimum_required(VERSION 3.16.3)
project(Server)
project(Client)

set(CMAKE_CXX_STANDARD 11)

add_executable(Server Server/main.cpp Server/Knn.cpp Server/Knn.h Iris.h
        Iris.cpp Server/UDPServer.h Server/UDPServer.cpp Server/TCPServer.cpp Server/TCPServer.h)
add_executable(Client Client/main.cpp Client/UDPClient.cpp Client/UDPClient.h Client/TCPClient.cpp
        Client/TCPClient.h Iris.h Iris.cpp)

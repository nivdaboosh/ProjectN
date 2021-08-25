#include <string>
#include "TCPServer.h"
#include "UDPServer.h"

int main(int argc, char *argv[]) {
    if (std::string(argv[1]) == "UDP") {
        UDPServer::UdpServer();
    } else if (std::string(argv[1]) == "TCP") {
        TCPServer::TcpServer();
    } else {
        perror("Wrong protocol");
    }
}
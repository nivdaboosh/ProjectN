#include <iostream>
#include <algorithm>
#include <cstring>
#include <sys/socket.h>
#include <cstdio>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <vector>

using namespace std;

#include "TCPServer.h"
#include "Knn.h"

int TCPServer::TcpServer() {
    const char *ip_address = "127.0.0.1";
    const int port_no = 55755;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no);

    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
    }

    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
        perror("Connection is closed");
    } else if (read_bytes < 0) {
        perror("Error reading message");
    } else {
        cout << buffer;
    }

    Knn knn = Knn();
    std::vector<string> list = knn.run(buffer);
    for (int i = 0; i < list.size(); ++i) {
        char data_addr[list[i].size()];
        strcpy(data_addr, list[i].c_str());
        int data_len = sizeof(data_addr);
        int sent_bytes = send(sock, data_addr, data_len, 0);
        if (sent_bytes < 0) {
            perror("Error reading message");
        }
    }

    close(sock);
    return 0;
}
#include <iostream>
#include <algorithm>
#include <cstring>
#include <sys/socket.h>
#include <cstdio>
#include <netinet/in.h>
#include <vector>
#include <arpa/inet.h>
#include <unistd.h>

#include "../Iris.h"
#include "UDPClient.h"

using namespace std;

std::vector<string> UDPClient::UdpClient(string unClassified) {
    const char *ip_address = "127.0.0.1";
    const int port_no = 5556;

    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no);

    char data[unClassified.size()];
    strcpy(data, unClassified.c_str());
    int data_len = sizeof(data);

    int sent_bytes = sendto(sock, data, data_len, 0, (struct sockaddr *) &sin, sizeof(sin));
    if (sent_bytes < 0) {
        perror("error sending message");
    }

    struct sockaddr_in from;
    unsigned int from_len = sizeof(struct sockaddr_in);
    char buffer[4096];
    // לולאה
    int bytes = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr *) &from, &from_len);
    std::vector<string> output;
    if (bytes < 0) {
        perror("error reading message");
    } else {
        output.emplace_back(buffer);
    }
    close(sock);
    return output;
}
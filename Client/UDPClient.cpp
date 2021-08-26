#include <iostream>
#include <algorithm>
#include <cstring>
#include <sys/socket.h>
#include <cstdio>
#include <netinet/in.h>
#include <vector>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

#include "../Iris.h"
#include "UDPClient.h"

sockaddr_in UDPClient::connecting() {
    const char *ip_address = "127.0.0.1";
    const int port_no = 55756;

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no);

    return sin;
}

std::vector<string> UDPClient::UdpClient(string unClassified, sockaddr_in sin) {

    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }


    char data[unClassified.size()];
    strcpy(data, unClassified.c_str());
    int data_len = sizeof(data);

    int sent_bytes = sendto(sock, data, data_len, 0, (struct sockaddr *) &sin, sizeof(sin));
    if (sent_bytes < 0) {
        perror("error sending message");
    }

    struct sockaddr_in from;
    unsigned int from_len = sizeof(struct sockaddr_in);
    std::vector<string> output;
    char buffer[4096];
    int bytes = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr *) &from, &from_len);
    if (bytes < 0) {
        perror("error reading message");
    } else {
        string theBuffer(buffer);
        output = Iris::strToVector(theBuffer, '$');
    }
    close(sock);
    return output;
}
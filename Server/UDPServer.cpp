#include <iostream>
#include <sys/socket.h>
#include <cstdio>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <algorithm>

using namespace std;

#include "Knn.h"
#include "UDPServer.h"

int UDPServer::UdpServer() {
    const int server_port = 55756;

    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }

    struct sockaddr_in sin;

    memset(&sin, 0, sizeof(sin));

    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);

    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding to socket");
    }

    struct sockaddr_in from;
    unsigned int from_len = sizeof(struct sockaddr_in);
    char buffer[4096];
    int bytes = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr *) &from, &from_len);
    cout << "l" << endl;
    if (bytes < 0) {
        perror("error reading from socket");
    }

    Knn knn = Knn();
    std::vector<string> output = knn.run(buffer);
    string theOutput;
    for (int i = 0; i < output.size(); ++i) {
        theOutput += output[i];
        theOutput += "$";
    }
    int sent_bytes = sendto(sock, theOutput.c_str(), strlen(theOutput.c_str()), 0, (struct sockaddr *) &from,
                            sizeof(from));
    if (sent_bytes < 0) {
        perror("error writing to socket");
    }
    close(sock);

    return 0;
}
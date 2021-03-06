#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>
#include <netinet/in.h>

using namespace std;

#include "TCPClient.h"
#include "UDPClient.h"

/**
 * The main of the client.
 * @return int.
 */
int main() {
    string input;
    getline(cin, input);
    string protocol = strtok(const_cast<char *>(input.c_str()), " ");
    string unclassified = strtok(nullptr, " ");
    string output = strtok(nullptr, " ");
    std::vector<string> text;
    struct sockaddr_in TCPSin = TCPClient::connecting();
    struct sockaddr_in UDPSin = UDPClient::connecting();
    if (protocol == "TCP") {
        text = ::TCPClient::TcpClient(unclassified, TCPSin);
    } else if (protocol == "UDP") {
        text = UDPClient::UdpClient(unclassified, UDPSin);
    } else {
        perror("Wrong protocol");
    }
    // Opens a file.
    std::ofstream fout(output);
    for (int i = 0; i < text.size() - 1; ++i) {
        fout << text[i] << endl;
    }
    fout << text[text.size() - 1];
    fout.close();
    return 0;
}
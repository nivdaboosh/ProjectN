#include <vector>
#include <cstdio>

using namespace std;

#ifndef CLIENT_CPP_UDPCLIENT_H
#define CLIENT_CPP_UDPCLIENT_H


class UDPClient {
public:
    /**
     * Connecting to UDP.
     * @return sockaddr_in.
     */
    static sockaddr_in connecting();

    /**
     * Running the UDP client.
     * @param unClassified string.
     * @param sin sockaddr_in.
     * @return std::vector<string>
     */
    static std::vector<string> UdpClient(string unClassified, sockaddr_in sin);
};


#endif //CLIENT_CPP_UDPCLIENT_H
#include "BaseSocket.h"
class ListenSocket : Socket{
    int clientSocket = -1;
    std::string recieve = "";
public:
    ListenSocket();
    void l_connect();
    void closing_sock();
    std::string listen_s();
    bool send_OK();
    ~ListenSocket();
 
};
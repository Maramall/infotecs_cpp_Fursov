#include "BaseSocket.h"
class ListenSocket : Socket{
    int clientSocket = -1;
public:
    ListenSocket();
    int l_connect();
    std::string listen_s();
    ~ListenSocket();
 
};
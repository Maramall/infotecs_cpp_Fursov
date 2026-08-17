#include "BaseSocket.h"
class ListenSocket : Socket{
    bool is_listening = false;
public:
    ListenSocket();
    int l_connect();
    std::string listen_s();
    ~ListenSocket();
 
};
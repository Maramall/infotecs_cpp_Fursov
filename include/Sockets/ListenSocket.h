#include "BaseSocket.h"
class ListenSocket : Socket{
    bool is_listening = false;
public:
    ListenSocket();
    std::string listen_s();
    ~ListenSocket();
 
};
#include "BaseSocket.h"
class SenderSocket : Socket{
    bool connected = false;
    public:
    SenderSocket();
    bool connect_s();
    void disconnect(); 
    bool send_s(int to_send);
    ~SenderSocket();
};

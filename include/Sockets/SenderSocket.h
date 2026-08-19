#include "BaseSocket.h"
class SenderSocket : Socket{
    bool connected = false;
    public:
    SenderSocket();
    int connect_s();
    int send_s(int to_send);
    ~SenderSocket();
};

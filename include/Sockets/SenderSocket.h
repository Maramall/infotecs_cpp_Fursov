#include "BaseSocket.h"
class SenderSocket : Socket{
    public:
    SenderSocket();
    int s_connect();
    int send_s(int to_send);
    ~SenderSocket();
};

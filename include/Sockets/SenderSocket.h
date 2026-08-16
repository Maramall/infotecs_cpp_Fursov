#include "BaseSocket.h"
class SenderSocket : Socket{
    public:
    SenderSocket();
    void send_s(int to_send);
    ~SenderSocket();
};

#include <cstring>
#include <iostream>

#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

class Socket{
    int inf_socket = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddress;
   public: 
    Socket(bool is_client);
    
    void listen_s();
    void send_s();
    
    ~Socket();
}; 
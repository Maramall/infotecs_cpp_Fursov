#include <cstring>
#include <iostream>

#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

class Socket{
    protected:
    int adr_socket = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddress;
   public: 
    Socket();
       
    ~Socket();
}; 



    
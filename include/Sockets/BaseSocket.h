#include <cstring>
#include <iostream>

#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>


#include <cerrno>

class Socket{
    protected:
    int adr_socket;
    sockaddr_in serverAddress;
   public: 
    Socket();
       
    ~Socket();
}; 



    
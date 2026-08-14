#include "../include/lib.h"
#include "../include/Sockets/ListenSocket.h"
#include <string>



int main(){
    ListenSocket server;

    std::string sr = "He12llo44";
    sort_and_replace(sr);
    while(1){
        server.listen_s();
    }
   // std::cout << sum_elems(sr) << "\n" << sr;

}
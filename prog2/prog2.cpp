#include "../include/lib.h"
#include "../include/Sockets/SenderSocket.h"
#include <string>



int main(){
    SenderSocket client;

    std::string sr = "He12llo44";
    sort_and_replace(sr);
    client.send_s();
    
 //   std::cout << sum_elems(sr) << "\n" << sr;

}
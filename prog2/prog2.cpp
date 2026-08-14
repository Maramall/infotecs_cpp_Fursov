#include "../include/lib.h"
#include "../include/to_socket.h"
#include <string>



int main(){
    Socket client(true);

    std::string sr = "He12llo44";
    sort_and_replace(sr);
    client.send_s();
    
 //   std::cout << sum_elems(sr) << "\n" << sr;

}
#include "../include/lib.h"
#include "../include/Sockets/SenderSocket.h"
#include <vector>

#include <mutex>
#include <pthread.h>
    std::vector<std::string> buffer;
    std::mutex mtx;

bool is_only_digit_and_len_less_64(const std::string &str){

    if(str.size() > 64)
        return false;
    for(auto &e : str){
        if(e < '0' || e > '9')
            return false;
    }
    return true;
}

void* first_thread(void* args){
    while(true){
        std::string sr = "\0";  
        std::cin >> sr;
        if(is_only_digit_and_len_less_64(sr)){
            sort_and_replace(sr);
          
            {
                std::lock_guard<std::mutex> lock_buffer(mtx);
                buffer.push_back(sr);
            }
           
           // std::cout << "buffer size is: " << buffer.size() << "\n";
        }
    }
}

void* second_thread(void* args){
    bool for_error = true;
    int to_prog2 = 0; 
   while(true){
    
        if(buffer.size()){
            
            if(for_error){
            
                std::lock_guard<std::mutex> lock_buffer(mtx);
                std::string from_buffer = buffer[buffer.size()-1];        
                //std::cout << from_buffer;
                to_prog2 = sum_elems(from_buffer);
              
            }
            try{
                SenderSocket client;
                client.send_s(to_prog2);
                
                std::lock_guard<std::mutex> lock_buffer(mtx);
                buffer.pop_back();
                for_error = true;
                

            }
            catch(std::logic_error& msg){
                if(for_error){
                    std::cerr << msg.what() << '\n';
                    for_error = false;
                }
            }
        }
    }
}


int main(){
    


    pthread_t thread1, thread2;
    if(pthread_create(&thread1, NULL, first_thread, NULL)){
        return -1;
    }
    if(pthread_create(&thread2, NULL, second_thread, NULL)){
        return -1;
    }
    
    if(pthread_join(thread1, NULL)){
        return -1;
    }
    if(pthread_join(thread2, NULL)){
        return -1;
    }    

    return 0;
}
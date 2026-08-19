#include "../include/lib.h"
#include "../include/Sockets/SenderSocket.h"

#include <vector>

#include <mutex>
#include <condition_variable>
#include <thread>


std::vector<std::string> buffer;
    std::mutex mtx;
    std::condition_variable to_sec_thr;
    bool send_to_cv = false;
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
        send_to_cv = true;  
        to_sec_thr.notify_one();
        std::cin >> sr;
        if(is_only_digit_and_len_less_64(sr)){
            sort_and_replace(sr);
                send_to_cv = false;
                std::unique_lock<std::mutex> lock_buffer(mtx);
            
                buffer.push_back(sr);
                send_to_cv = true;
                to_sec_thr.notify_one();
           // std::cout << "buffer size is: " << buffer.size() << "\n";
        }
    }
}

void* second_thread(void* args){
    bool for_error = false;
    int to_prog2 = 0; 
    SenderSocket client;
   while(true){
        
        std::unique_lock<std::mutex> ul(mtx);
        to_sec_thr.wait(ul, [](){return send_to_cv;});
        
        if (!client.connect_s()){
                if(buffer.size()){
                        std::string from_buffer = buffer[buffer.size()-1];        
                        to_prog2 = sum_elems(from_buffer);

                    if(client.send_s(to_prog2) != -1){
                        buffer.pop_back();                    
                    }
            } 
        }
        send_to_cv = false;
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
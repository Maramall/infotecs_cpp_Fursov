cmake_minimum_required(VERSION 3.16)

project(Fursov_test LANGUAGES CXX) 

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


add_library(Lib SHARED src/lib.cpp)
add_library(Sockets SHARED src/Sockets/BaseSocket.cpp src/Sockets/ListenSocket.cpp src/Sockets/SenderSocket.cpp)

target_include_directories(Lib PUBLIC include)
target_include_directories(Sockets PUBLIC include)

add_executable(pr1 prog1/prog1.cpp) 
target_link_libraries(pr1 PRIVATE Lib Sockets)

add_executable(pr2 prog2/prog2.cpp) 
target_link_libraries(pr2 PRIVATE Lib Sockets)
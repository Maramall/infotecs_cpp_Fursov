cmake_minimum_required(VERSION 4.0.3) #показывает какой минимальной версией можно собрать проект

project(Fursov_test) #дает имя проекту

#дает понять что будет собираться исполняеый файл(exe)
#первый аргумент - это название собираемоего проекта, остальные исходные файлы *.h *.cpp
#все аргументы записываются через пробел
add_library(Lib SHARED src/lib.cpp)
add_library(Sockets SHARED src/Sockets/BaseSocket.cpp src/Sockets/ListenSocket.cpp src/Sockets/SenderSocket.cpp)

add_executable(pr1 prog_one/prog1.cpp) 
target_link_libraries(pr1 Lib Sockets)

add_executable(pr2 prog2/prog2.cpp) 
target_link_libraries(pr2 Lib Sockets)
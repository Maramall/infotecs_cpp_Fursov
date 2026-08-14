cmake_minimum_required(VERSION 4.0.3) #показывает какой минимальной версией можно собрать проект

project(Fursov_test) #дает имя проекту

#дает понять что будет собираться исполняеый файл(exe)
#первый аргумент - это название собираемоего проекта, остальные исходные файлы *.h *.cpp
#все аргументы записываются через пробел
add_library(Lib SHARED src/lib.cpp)
add_library(to_socket SHARED src/to_socket.cpp)

add_executable(pr1 prog_one/prog1.cpp) 
target_link_libraries(pr1 Lib to_socket)

add_executable(pr2 prog2/prog2.cpp) 
target_link_libraries(pr2 Lib to_socket)
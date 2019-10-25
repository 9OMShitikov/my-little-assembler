cmake_minimum_required(VERSION 3.10)

project(my_compiler)
set(CMAKE_CXX_STANDARD 17)
add_executable(my_compiler my_compiler.cpp)

project(my_disassembler)
set(CMAKE_CXX_STANDARD 17)
add_executable(my_disassembler my_disassembler.cpp)

project(my_executor)
set(CMAKE_CXX_STANDARD 17)
add_executable(my_executor my_executor.cpp)

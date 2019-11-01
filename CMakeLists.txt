cmake_minimum_required(VERSION 3.10)

project(my_compiler)
set(CMAKE_CXX_STANDARD 17)

include_directories("auxilary_structures")
include_directories("compiler_information")
include_directories("defines_packs")
include_directories("processor")

add_executable(my_compiler main_files/my_compiler.cpp)

project(my_disassembler)
set(CMAKE_CXX_STANDARD 17)
add_executable(my_disassembler main_files/my_disassembler.cpp)

project(my_executor)
set(CMAKE_CXX_STANDARD 17)
add_executable(my_executor main_files/my_executor.cpp)

cmake_minimum_required(VERSION 3.24)
project(Library_Management_System)

set(CMAKE_CXX_STANDARD 17)

add_executable(Library_Management_System main.cpp Book.h Member.h Library.h)

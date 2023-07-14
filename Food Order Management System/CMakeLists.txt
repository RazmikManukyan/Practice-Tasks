cmake_minimum_required(VERSION 3.24)
project(Food_Order_Management_System)

set(CMAKE_CXX_STANDARD 17)

add_executable(Food_Order_Management_System main.cpp MenuItem.h Restaurant.h Customer.h Order.h OrderManagementSystem.h)

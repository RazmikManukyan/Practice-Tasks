cmake_minimum_required(VERSION 3.24)
project(Electricity_Billing_System_)

set(CMAKE_CXX_STANDARD 17)

add_executable(Electricity_Billing_System_ main.cpp Customer.h ElectricityBill.h ElectricityBillingSystem.h)

cmake_minimum_required(VERSION 3.24)
project(Blood_Bank_Management_System)

set(CMAKE_CXX_STANDARD 17)

add_executable(Blood_Bank_Management_System main.cpp Donor.h BloodOperation.h BloodBankManagementSystem.h)

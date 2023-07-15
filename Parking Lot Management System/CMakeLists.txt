cmake_minimum_required(VERSION 3.24)
project(Parking_Lot_Management_System)

set(CMAKE_CXX_STANDARD 17)

add_executable(Parking_Lot_Management_System main.cpp ParcingSpace.h User.h Receipt.h ParkingLotManagementSystem.h)

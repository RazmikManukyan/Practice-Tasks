cmake_minimum_required(VERSION 3.24)
project(HotelRS)

set(CMAKE_CXX_STANDARD 17)

add_executable(HotelRS main.cpp Room.h Customer.h Reservation.h Hotel.h)

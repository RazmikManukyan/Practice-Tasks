cmake_minimum_required(VERSION 3.24)
project(Taxi_Booking_System)

set(CMAKE_CXX_STANDARD 17)

add_executable(Taxi_Booking_System main.cpp Taxi.h User.h Ride.h TaxiBookingSystem.h)

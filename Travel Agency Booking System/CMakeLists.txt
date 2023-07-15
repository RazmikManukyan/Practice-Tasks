cmake_minimum_required(VERSION 3.24)
project(Travel_Agency_Booking_System)

set(CMAKE_CXX_STANDARD 17)

add_executable(Travel_Agency_Booking_System main.cpp TravelPackage.h User.h Ticket.h TravelAgencyBookingSystem.h)

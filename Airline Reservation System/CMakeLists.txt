cmake_minimum_required(VERSION 3.24)
project(Airline_Reservation_System)

set(CMAKE_CXX_STANDARD 17)

add_executable(Airline_Reservation_System main.cpp Flight.h User.h Ticket.h AirplaneReservationSystem.h)

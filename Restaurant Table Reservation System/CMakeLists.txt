cmake_minimum_required(VERSION 3.24)
project(Restaurant_Table_Reservation_System)

set(CMAKE_CXX_STANDARD 17)

add_executable(Restaurant_Table_Reservation_System main.cpp Table.h User.h Reservation.h ReservationSystem.h)

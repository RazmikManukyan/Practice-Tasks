cmake_minimum_required(VERSION 3.24)
project(Ticket_Booking_System_for_Cinema)

set(CMAKE_CXX_STANDARD 17)

add_executable(Ticket_Booking_System_for_Cinema main.cpp Movie.h User.h Ticket.h CinemaTicketBookingSystem.h)

cmake_minimum_required(VERSION 3.24)
project(Job_Portal_System)

set(CMAKE_CXX_STANDARD 17)

add_executable(Job_Portal_System main.cpp Job.h User.h JobPortalSystem.h)

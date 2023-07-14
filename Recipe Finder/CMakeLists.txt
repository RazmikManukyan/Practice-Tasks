cmake_minimum_required(VERSION 3.24)
project(Recipe_Finder)

set(CMAKE_CXX_STANDARD 17)

add_executable(Recipe_Finder main.cpp Recipe.h RecipeFinder.h)

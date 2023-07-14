cmake_minimum_required(VERSION 3.24)
project(Expense_Tracker)

set(CMAKE_CXX_STANDARD 17)

add_executable(Expense_Tracker main.cpp Expense.h ExpenseTracker.h)

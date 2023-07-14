cmake_minimum_required(VERSION 3.24)
project(Customer_Relationship_Management__CRM__System)

set(CMAKE_CXX_STANDARD 17)

add_executable(Customer_Relationship_Management__CRM__System main.cpp Customer.h Interaction.h SaleInteraction.h WarrantyServiceInteraction.h ComplaintInteraction.h CRMSystem.h)

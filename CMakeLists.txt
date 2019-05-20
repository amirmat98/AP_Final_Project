cmake_minimum_required(VERSION 3.13)
project(phase_1)

set(CMAKE_CXX_STANDARD 11)

add_executable(phase_1 main.cpp Core.cpp Input_Handler.cpp User.cpp Publisher.cpp Customer.cpp Film.cpp Comment.cpp Message.cpp Message.h)
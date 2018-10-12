cmake_minimum_required(VERSION 3.10)
project(test_oop_18apr2018)

set(CMAKE_CXX_STANDARD 11)

add_executable(test_oop_18apr2018 main.cpp UserInterface.cpp UserInterface.h Project.cpp Project.h Repository.cpp Repository.h Controller.cpp Controller.h RunTests.cpp RunTests.h)
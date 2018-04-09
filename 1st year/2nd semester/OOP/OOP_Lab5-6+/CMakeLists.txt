cmake_minimum_required(VERSION 3.9)
project(lab5_6)

set(CMAKE_CXX_STANDARD 11)

add_executable(lab5_6 main.cpp Axolotl.cpp Axolotl.h UserInterface.cpp UserInterface.h DynamicVector.cpp DynamicVector.h Controller.cpp Controller.h Validator.cpp Validator.h RunTests.cpp RunTests.h)

include(CodeCoverage.cmake)

APPEND_COVERAGE_COMPILER_FLAGS()
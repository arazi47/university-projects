cmake_minimum_required(VERSION 3.10)
project(SortedBagBST)

set(CMAKE_CXX_STANDARD 11)

add_executable(SortedBagBST main.cpp AbstractSortedBag.cpp AbstractSortedBag.hpp BSTIterator.cpp BSTIterator.hpp GlobalDefinitions.hpp BST.cpp BST.hpp RunTests.cpp RunTests.hpp)

include(CodeCoverage.cmake)

APPEND_COVERAGE_COMPILER_FLAGS()
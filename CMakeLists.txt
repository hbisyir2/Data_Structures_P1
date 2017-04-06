cmake_minimum_required(VERSION 3.5)
project(P1 CXX)

add_executable(completer completer.cpp search.h search.txx)
set_property(TARGET completer PROPERTY CXX_STANDARD 11)

enable_testing()

set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/deps/cxxtest)

find_package(CxxTest)
if(CXXTEST_FOUND)
  include_directories("${CXXTEST_INCLUDE_DIR}")	
  CXXTEST_ADD_TEST(search_test search_test.cc
    "${CMAKE_CURRENT_SOURCE_DIR}/search_test.h" search.h search.txx)
  set_property(TARGET search_test PROPERTY CXX_STANDARD 11)
endif()

cmake_minimum_required(VERSION 3.14)
project(sort)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)


add_executable(sort main.cpp sort.h sort_impl.h util.h util_impl.h Comparable.h Comparable.cpp test.cpp test.h test_impl.h)

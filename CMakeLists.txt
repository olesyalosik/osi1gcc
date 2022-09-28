cmake_minimum_required(VERSION 3.8)

project(osi1)

add_executable(osi1 main.cpp main.h reporter.cpp reporter.h creator.cpp creator.h)

# set c++ standard to c++98

set_property(TARGET osi1 PROPERTY CXX_STANDARD 98)

# ask for c++98 to be required (and not just a best-effort request)

set_property(TARGET osi1 PROPERTY CXX_STANDARD_REQUIRED ON)

cmake_minimum_required(VERSION 3.8)

project(osi1lab)

add_executable(osi1 main.cpp main.h reporter.cpp reporter.h creator.cpp creator.h)

# set c++ standard to c++98

#set_property(TARGET osi1 PROPERTY CMAKE_CXX_STANDARD 98)
#set_property(TARGET osi1 PROPERTY CMAKE_CXX_EXTENSIONS OFF)

# ask for c++98 to be required (and not just a best-effort request)

SET ( CMAKE_CXX_FLAGS "-std=c++98" CACHE STRING "compile flags" FORCE)

#set_property(TARGET osi1 PROPERTY CMAKE_CXX_STANDARD_REQUIRED ON)

#variable_watch(CMAKE_CXX_FLAGS)
#set_property(TARGET osi1 PROPERTY GLIBCXX_USE_CXX11_ABI False)
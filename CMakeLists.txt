
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

# CXX = g++
cmake_minimum_required(VERSION 3.10)

# set(MAKE_CXX_COMPILER '/usr/bin/g++')

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()


set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wc++11-extensions -mavx2")
set(CMAKE_CXX_FLAGS_DEBUG "-g -Wc++11-extensions -mavx2")
set(CMAKE_CXX_FLAGS_RELEASE "-Os -Wc++11-extensions -mavx2")
set(CMAKE_CXX_STANDARD 14)
add_definitions(-w)
add_definitions(-mavx2) 

# set the project name
project(AoC2023)


# find_package(Boost 1.80 COMPONENTS program_options REQUIRED)

# add the executable
add_executable(entry entry.cpp)

# target_link_libraries(entry Boost::program_options)

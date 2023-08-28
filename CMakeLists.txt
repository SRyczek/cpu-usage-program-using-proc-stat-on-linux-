cmake_minimum_required(VERSION 3.15)
#project name
project(TietoevryProject)

#reading the CC environment variable 
if(DEFINED ENV{CC})
    set(CMAKE_C_COMPILER $ENV{CC})
endif()

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Weverything -g -pthread")

enable_testing()

#add folder with files
add_subdirectory(include)               
add_subdirectory(src)
add_subdirectory(tests)
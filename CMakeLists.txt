cmake_minimum_required(VERSION 3.15)
project(TietoevryProject)               #project name


set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_subdirectory(include)               #add folder with files
add_subdirectory(src)
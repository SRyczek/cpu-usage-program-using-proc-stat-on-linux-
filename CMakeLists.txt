cmake_minimum_required(VERSION 3.15)
project(TietoevryProject)               #project name
#add_executable(main main.c)            #first is exe file, second is main.c file

add_subdirectory(include)               #add folder with files
add_subdirectory(src)
add_subdirectory(example)
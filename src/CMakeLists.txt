
project(TietoevryProject)  #the same name as root project

add_library(include reader.c)



target_include_directories(
    include
    PUBLIC      #public/private/interface
    ${CAKE_CURRENT_SOURCE_DIR}/..
)
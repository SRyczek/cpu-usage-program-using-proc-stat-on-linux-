
project(TietoevryProject)  #the same name as root project

add_executable(main main.c)

add_library(include lib.c reader.c global.c analyzer.c printer.c watchDog.c logger.c)

target_link_libraries(main PUBLIC include)

target_include_directories(
    include
    PUBLIC      #public/private/interface
    ${CAKE_CURRENT_SOURCE_DIR}/..
)

# enable testing functionality
enable_testing()

# main code
add_executable(bufferTest test1.c)
target_link_libraries(bufferTest PRIVATE include)

add_test(Test1 bufferTest test1)


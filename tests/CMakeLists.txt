

# enable testing functionality
enable_testing()

# main code
add_executable(bufferTest test1.c)
add_test(BufferTest bufferTest)
target_link_libraries(bufferTest PRIVATE include)



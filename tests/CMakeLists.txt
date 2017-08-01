add_subdirectory(test_server)

add_executable(test1 test1.cpp)
target_link_libraries(test1 libGPCInterproc)

add_test(NAME test1 COMMAND test1 $<TARGET_FILE:test_server>)


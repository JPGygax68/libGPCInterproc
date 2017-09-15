
add_subdirectory(test_server)

add_executable(test1 test1.cpp)

target_link_libraries(test1 libgpcinterproc)

set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost REQUIRED COMPONENTS filesystem date_time)
target_include_directories(test1 PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(test1 ${Boost_LIBRARIES})


add_test(NAME test1 COMMAND test1 $<TARGET_FILE:test_server>)


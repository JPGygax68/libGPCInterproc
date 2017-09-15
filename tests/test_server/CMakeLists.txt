project(test_server)


add_executable(test_server
  main.cpp
)

target_link_libraries(test_server PRIVATE libgpcinterproc)
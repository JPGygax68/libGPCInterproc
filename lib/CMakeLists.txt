project(libgpcinterproc)

add_library(${PROJECT_NAME}
  
  include/gpc/interproc/Lock_free_ringbuffer.hpp src/Lock_free_ringbuffer.cpp
  
  conanfile.txt
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Dependency: Boost

set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost REQUIRED date_time)
target_include_directories(${PROJECT_NAME} PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PUBLIC ${Boost_LIBRARIES})

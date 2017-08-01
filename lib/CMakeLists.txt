
include(${CMAKE_BINARY_DIR}/conanbuildinfo_multi.cmake)
conan_basic_setup(TARGETS)


add_library(${PROJECT_NAME}
  
  include/gpc/interproc/Lock_free_ringbuffer.hpp src/Lock_free_ringbuffer.cpp
  
  conanfile.txt
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} PUBLIC CONAN_PKG::boost)


include(${CMAKE_BINARY_DIR}/conanbuildinfo_multi.cmake)
conan_basic_setup()


add_library(${PROJECT_NAME}
  
  include/gpcinterproc/gpcinterproc.hpp src/gpcinterproc.cpp
  
  conanfile.txt
)

target_include_directories(${PROJECT_NAME} PUBLIC $(CMAKE_CURRENT_SOURCE_DIR)/include)

conan_target_link_libraries(${PROJECT_NAME})
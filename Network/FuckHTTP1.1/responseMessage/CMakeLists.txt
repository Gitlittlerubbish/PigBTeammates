cmake_minimum_required(VERSION 3.2)
project(ResponseMessageDemoTest)
add_compile_options(
    -Wall
    -g
    -std=c++11
)

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

file(GLOB RSP_SRC_LIST ${CMAKE_SOURCE_DIR}/src/*.cpp)
add_library(rsp_msg ${RSP_SRC_LIST})
target_include_directories(rsp_msg PUBLIC ${CMAKE_SOURCE_DIR}/include)

message("source dir: ${CMAKE_SOURCE_DIR}")
message("RSP_SRC_LIST: ${RSP_SRC_LIST}")

# 启用测试
enable_testing()
add_subdirectory(test)
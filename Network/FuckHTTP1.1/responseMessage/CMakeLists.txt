cmake_minimum_required(VERSION 3.1)
project(ResponseMessageDemoTest)
add_compile_options(
    -Wall
    -g
)

file(GLOB RSP_SRC_LIST ${CMAKE_SOURCE_DIR}/src/*.cpp)
add_library(rsp_msg ${RSP_SRC_LIST})
target_include_directories(rsp_msg PUBLIC ${CMAKE_SOURCE_DIR}/include)

message("source dir: ${CMAKE_SOURCE_DIR}")
message("RSP_SRC_LIST: ${RSP_SRC_LIST}")

# 启用测试
enable_testing()
add_subdirectory(test)
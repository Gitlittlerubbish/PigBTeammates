cmake_minimum_required(VERSION 3.1)
project(ResponseMessageDemoTest)
add_compile_options(
    -Wall
    -g
)

file(GLOB RSP_SRC_LIST ${CMAKE_SOURCE_DIR}/src/*.cpp)
add_library(rsp_msg ${RSP_SRC_LIST})
target_include_directories(rsp_msg PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(test_rsp_msg
                ${CMAKE_SOURCE_DIR}/test/demo_test.cpp)
target_link_libraries(test_rsp_msg PUBLIC rsp_msg)
target_include_directories(test_rsp_msg PUBLIC ${CMAKE_SOURCE_DIR}/include)

message("source dir: ${CMAKE_SOURCE_DIR}")
message("RSP_SRC_LIST: ${RSP_SRC_LIST}")

# 启用测试
enable_testing()

# 测试程序是否成功运行
add_test(test_run test_rsp_msg)

# 测试输出payload
add_test(test_output_payload test_rsp_msg)
set_tests_properties (test_output_payload
                        PROPERTIES PASS_REGULAR_EXPRESSION "FUCK_THIS_IS_THE_TEST_PAYLOAD")

# TEST HTTP VERSION
add_test(test_http_version test_rsp_msg)
set_tests_properties (test_http_version
                        PROPERTIES PASS_REGULAR_EXPRESSION "HTTP/1.1")

# TEST STATUS CODE
add_test(test_status_code test_rsp_msg)
set_tests_properties (test_status_code
                        PROPERTIES PASS_REGULAR_EXPRESSION "200")

# TEST STATUS CODE DESCRIPTION
add_test(test_status_code_description test_rsp_msg)
set_tests_properties (test_status_code_description
                        PROPERTIES PASS_REGULAR_EXPRESSION "OK")
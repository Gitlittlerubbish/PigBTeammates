cmake_minimum_required(VERSION 3.1)
project(ResponseMessageDemoTest)


file(GLOB FILE_LIST ${CMAKE_SOURCE_DIR}/*.cpp)
include_directories(${CMAKE_SOURCE_DIR}/../../include)
add_compile_options(
    -Wall
    -g
)

add_executable(demo_test
                ${FILE_LIST})

message("source dir: ${CMAKE_SOURCE_DIR}")
message("FILE_LIST: ${FILE_LIST}")


# 启用测试
enable_testing()

# 测试程序是否成功运行
add_test(test_run demo_test)

# 测试输出payload
add_test(test_output_payload demo_test)
set_tests_properties (test_output_payload
                        PROPERTIES PASS_REGULAR_EXPRESSION "FUCK_THIS_IS_THE_TEST_PAYLOAD")

# TEST HTTP VERSION
add_test(test_http_version demo_test)
set_tests_properties (test_http_version
                        PROPERTIES PASS_REGULAR_EXPRESSION "HTTP/1.1")

# TEST STATUS CODE
add_test(test_status_code demo_test)
set_tests_properties (test_status_code
                        PROPERTIES PASS_REGULAR_EXPRESSION "200")

# TEST STATUS CODE DESCRIPTION
add_test(test_status_code_description demo_test)
set_tests_properties (test_status_code_description
                        PROPERTIES PASS_REGULAR_EXPRESSION "OK")



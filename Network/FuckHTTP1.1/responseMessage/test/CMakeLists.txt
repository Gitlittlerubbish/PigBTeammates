
add_compile_options(-L-usr/local/lib64)
add_executable(test_rspmsg main.cpp)
target_include_directories(test_rspmsg PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(test_rspmsg rsp_msg gtest gtest_main pthread)
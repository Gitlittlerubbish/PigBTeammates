# add_subdirectory(../../googletest exclude_from_all)
add_executable(test_rspmsg main.cpp)
target_link_libraries(test_rspmsg rsp_msg gtest_main)
add_test(test_rspmsg test_rspmsg)
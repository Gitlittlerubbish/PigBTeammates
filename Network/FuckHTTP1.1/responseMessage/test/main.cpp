#include <gtest/gtest.h>
#include "ResponseMessage.h"

TEST(test_rsp, test1) {
    ASSERT_EQ(0, 0);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

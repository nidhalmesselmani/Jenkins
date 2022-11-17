#include<iostream>
#include<gtest/gtest.h>

TEST(TestName, Subtest_1)
{
    EXPECT_EQ(2,2);
    std::cout << "After assertion" << std::endl;
}
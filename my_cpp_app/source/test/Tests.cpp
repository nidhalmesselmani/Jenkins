#include<iostream>
#include<gtest/gtest.h>

TEST(Tests,SubTest1){
    std::cout << "this is a test";
    ASSERT_EQ(1,1);
}
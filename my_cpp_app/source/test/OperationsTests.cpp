#include<gtest/gtest.h>

int MAC(int x, int y, int& sum){
    sum+= x * y;
    return sum; 
}

int side_effect = 42;
bool f(){
    side_effect =16;
    return false;
}

TEST(OperationsTests, MAC){
    int x = 42;
    int y = 16;
    int sum = 100;
    int oldSum = sum;
    int expectedNewSum = oldSum + x * y;
    EXPECT_EQ(
        oldSum + x * y,
        MAC(x,y,sum)
    );
    EXPECT_EQ(
        expectedNewSum,
        sum
    );
}
#include<iostream>
#include<gtest/gtest.h>

class MyClass {
    std::string id;
public:
    MyClass(std::string _id) : id(_id){}
    std::string GetId() { return id; }
};

TEST(TestName, increment_by_5)
{
    // Arrange
    MyClass mc("root");


    // Act
    std::string value = mc.GetId();

    // Assert
    EXPECT_STREQ(value.c_str(),"root");

}

TEST(TestName, increment_by_10)
{
    // Arrange
    int value = 100;
    int increment = 10;

    // Act
    value = value + increment;

    // Assert
    ASSERT_EQ(value,110);

}
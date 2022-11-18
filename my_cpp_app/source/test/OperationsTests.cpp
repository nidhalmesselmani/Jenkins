#include<iostream>
#include<gtest/gtest.h>
#include<vector>

class Stack {
    std::vector<int> vstack = {};
public:
    void push(int value) { vstack.push_back(value); }
    int pop() { 
        if (vstack.size() > 0 ) {
            int value = vstack.back();
            vstack.pop_back();
            return value;
        }else{
            return -1;
        }
    }
    int size() {  return vstack.size();  }
};

class MyClass {
    int baseValue;
public:
    MyClass(int _bv) : baseValue(_bv){}
    void Increment(int byValue){
        baseValue += byValue;
    }
    int GetValue() { return baseValue; }
};

struct stackTest : public testing::Test {
    Stack s1;
    void SetUp() { 
        std::cout <<"Alive Stack"<< std::endl;
        int value[] = {1,2,3,4,5,6,7,8,9};
        for (auto &val : value){
            s1.push(val);
        }
                 
    }
    void TearDown() { std::cout <<"DEAD stack"<< std::endl;}
};

TEST_F(stackTest, PopTest){
    // ACT
    int lastPoppedValue = 9;
    // ASSERT
    while(lastPoppedValue != 1)
        ASSERT_EQ(s1.pop(), lastPoppedValue--);
}
TEST_F(stackTest, sizeValidityTest){
    // ACT
    int val = s1.size();
    // ASSERT
    for(val; val > 0; val--)
        ASSERT_NE(s1.pop(), -1);
}


struct MyClassTest : public testing::Test {
    MyClass *mc;
    void SetUp() { std::cout <<"Alive"<< std::endl;  mc = new MyClass(100) ;}
    void TearDown() { std::cout <<"DEAD"<< std::endl; delete mc;}
};

TEST_F(MyClassTest, increment_by_5){

    // Act
    mc->Increment(5);

    // ASSERT
    ASSERT_EQ(mc->GetValue(), 105);
}

TEST_F(MyClassTest, increment_by_10){

    // Act
    mc->Increment(10);

    // ASSERT
    ASSERT_EQ(mc->GetValue(), 110);
}

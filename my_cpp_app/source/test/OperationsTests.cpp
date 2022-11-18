#include<iostream>
#include<gtest/gtest.h>
#include<gmock/gmock.h>
#include<vector>

class DataBaseConnect {
public:
    virtual bool login(std::string username, std::string password){ std::cout << "Original Login...\n" ; return true; }
    virtual bool login2(std::string username, std::string password){ return true; }
    virtual bool logout(std::string username){ return true; }
    virtual int fetchRecord() { return -1; }
};

class MockDB : public DataBaseConnect{

public:
    MOCK_METHOD0(fetchRecord, int());
    MOCK_METHOD1(logout, bool(std::string username));
    MOCK_METHOD2(login, bool(std::string username, std::string passowrd));
    MOCK_METHOD2(login2, bool(std::string username, std::string passowrd));

};

// componenet which gonna use DataBaseConnect interface
class myDatabase {
    DataBaseConnect & dbC;
public:
    myDatabase(DataBaseConnect & _dbC) : dbC(_dbC) {}
    int Init(std::string username, std::string password) {
       /* int rvalue = rand() %2;
        if ( rvalue == 0) {*/ 
        if (dbC.login(username, password) != true){
             std::cout << "DB FAILURE" << std::endl; return -1;
        /*    if (dbC.login(username, password) != true)
                 std::cout << "DB FAILURE second time" << std::endl; return -1;*/

        }else{
             std::cout << "DB SUCCCES" << std::endl; return 1;
        }
       /* }else {
            return dbC.login2(username, password);
        }*/
    }
};

struct testABC {
    void dummyLogin(std::string a, std::string b){
        std::cout << "Dummy Login gets called\n";
        return;
    }
};
bool dummyFn(){
        std::cout << "Global Function Called \n";
        return true;
    }
TEST(MyDBTest, LogingTest){
    // Arrange
    MockDB mdb;
    myDatabase db(mdb);
    DataBaseConnect dbTest;
    testABC testABC;
    // EXPECT_CALL(mdb, login("Terminator", "Im Back")).Times(testing::AtLeast(1)).WillOnce(testing::Return(true));
    // we don't bother what is the parameter
    //EXPECT_CALL(mdb, login(testing::_,testing::_)).Times(testing::AtLeast(1)).WillOnce(testing::Return(true));
    // call the orignal implementation
    //EXPECT_CALL(mdb, login(testing::_,testing::_)).Times(testing::AtLeast(1)).WillOnce(testing::Invoke(&dbTest, &DataBaseConnect::login));
    // invoke function inside struct
    /*EXPECT_CALL(mdb, login(testing::_,testing::_))
    .Times(testing::AtLeast(1))
    .WillOnce(testing::Invoke(&testABC, &testABC::dummyLogin));*/
    // setting default actions
    /*ON_CALL(mdb, login(testing::_,testing::_)).WillByDefault(testing::Invoke(&testABC, &testABC::dummyLogin));
    
    EXPECT_CALL(mdb, login(testing::_,testing::_))
    .Times(testing::AtLeast(1))
    .WillOnce(testing::DoDefault());*/
    // Calling multiple actions
    EXPECT_CALL(mdb, login(testing::_,testing::_))
    .Times(testing::AtLeast(1))
    .WillOnce(testing::DoAll(testing::Invoke(&testABC, &testABC::dummyLogin),
    testing::Invoke(&testABC, &testABC::dummyLogin),
    testing::Return(false)));
    // Calling Global function it has to be without any argument if you want to call a global function
    /*EXPECT_CALL(mdb, login(testing::_,testing::_))
    .Times(testing::AtLeast(1))
    .WillOnce(testing::InvokeWithoutArgs(dummyFn));*/
    // this call need to be executed but if executed it will return true
    // this call need to be executed but if executed it will return true
    // ON_CALL(mdb, login(testing::_,testing::_)).WillByDefault(testing::Return(true));
   // ON_CALL(mdb, login2(testing::_,testing::_)).WillByDefault(testing::Return(true));
    // Act
    int retValue = db.Init("Terminatorsss", "I'll be Back");

    // ASSERT
    EXPECT_EQ(retValue, 1);
}
/*
TEST(MyDBTest, LoginFailure){
    // Arrange
    MockDB mdb;
    myDatabase db(mdb);
    // EXPECT_CALL(mdb, login("Terminator", "Im Back")).Times(testing::AtLeast(1)).WillOnce(testing::Return(true));
    // we don't bother what is the parameter
    EXPECT_CALL(mdb, login(testing::_,testing::_)).Times(testing::AtLeast(2)).WillRepeatedly(testing::Return(false));
    // Act
    int retValue = db.Init("Terminatorsss", "I'll be Back");

    // ASSERT
    EXPECT_EQ(retValue, -1);
}
*/
/*
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
*/
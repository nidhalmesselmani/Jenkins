#include<iostream>
#include<gtest/gtest.h>
#include <vector>
#include "../include/sum_integers.h"

TEST(Tests,SubTest1){
  
    std::cout << "this is a test\n" ;

    ASSERT_EQ(2,2);
}

TEST(SUM, sum_integers){
  auto integers = {1, 2, 3, 4, 5};
  ASSERT_EQ(sum_integers(integers), 15);
}
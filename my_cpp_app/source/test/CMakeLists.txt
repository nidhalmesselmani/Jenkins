#set(BINARY HelloApp)
cmake_minimum_required(VERSION 3.8)

set (This OperationsTests)

add_executable(${This} OperationsTests.cpp)
target_link_libraries(${This} PUBLIC gtest_main gmock_main operations)

add_test(
    NAME ${This}
    COMMAND ${This}
)

# example library
add_library(sum_integers ../src/sum_integers.cpp)


add_executable(Test Tests.cpp)
target_link_libraries(Test PUBLIC gtest_main gmock_main sum_integers)

add_test(
    NAME Test
    COMMAND Test
)

#set(BINARY HelloApp)
cmake_minimum_required(VERSION 3.8)

set (This HelloAppTests)

add_executable(${This} ExampleTests.cpp)
target_link_libraries(${This} PUBLIC gtest_main  operations)

add_test(
    NAME ${This}
    COMMAND ${This}
)
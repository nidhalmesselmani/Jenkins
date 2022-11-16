cmake_minimum_required(VERSION 3.5)
Project(HelloApp
        VERSION 0.0.1
        DESCRIPTION "The Hello World APP"
        LANGUAGES CXX)
add_executable(HelloAppBinary main.cpp)
target_compile_features(HelloAppBinary PRIVATE cxx_std_20)

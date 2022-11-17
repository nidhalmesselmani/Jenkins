cmake_minimum_required(VERSION 3.5)
Project(HelloApp
        VERSION 0.0.1
        DESCRIPTION "The Hello World APP"
        LANGUAGES CXX)

# GLOBING
#file(GLOB_RECURSE SOURCE_FILES src/*.cpp)
#add_executable(HelloAppBinary main.cpp ${SOURCE_FILES})

# List your sources
add_executable(HelloAppBinary main.cpp 
               src/dog.cpp 
               src/operations.cpp)

target_compile_features(HelloAppBinary PRIVATE cxx_std_20)
target_include_directories(HelloAppBinary PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
cmake_minimum_required(VERSION 3.5)

set(CXX_STANDARD_REQUIRED ON) # Make C++20 a hard requirement
set(CMAKE_CXX_STANDARD 20) # Default C++ standard for targets

Project(HelloApp
        VERSION 0.0.1
        DESCRIPTION "The Hello World APP"
        LANGUAGES CXX)

add_library(operations STATIC src/operations.cpp)
target_include_directories(operations PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
#target_compile_features(operations PUBLIC cxx_std_20)

add_library(logger STATIC logger/src/log.cpp)
target_include_directories(logger PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/logger/include)

# GLOBING
#file(GLOB_RECURSE SOURCE_FILES src/*.cpp)
#add_executable(HelloAppBinary main.cpp ${SOURCE_FILES})

# List your sources
add_executable(HelloAppBinary main.cpp 
               src/dog.cpp)

#target_compile_features(HelloAppBinary PRIVATE cxx_std_20)
target_include_directories(HelloAppBinary PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(HelloAppBinary PUBLIC operations logger )
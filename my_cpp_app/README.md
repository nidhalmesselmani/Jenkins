# CMAKE
cmake -G "MinGW Makefiles" ..\source\ == to generate file with specific generator
# WINDOW
mingw32-make.exe
# LINUX
make
# Generic build
cmake --build .
# Build specific target explicity
cmake --build . --target logger

cmake --build . --target operations

cmake --build . --target HelloAppBinary
# Gather information about the system running Cmake
cmake --system-information info.txt

# GTEST ASSERTS
EXPECT_EQ(,) EXPECT_NE(,) EXPECT_LT(,) EXPECT_LE(,) EXPECT_GT(,) EXPECT_GE(,)

ASSERT_EQ(,) ASSERT_NE(,) ASSERT_LT(,) ASSERT_LE(,) ASSERT_GT(,) ASSERT_GE(,)

EXPECT_TRUE( == ) EXPECT_FALSE( == ) 

ASSERT_TRUE( == ) ASSERT_FALSE( == )

EXPECT_STREQ(,) EXPECT_STRNE(,) EXPECT_STRCASEEQ(,) EXPECT_STRCASENE(,)

ASSERT_STREQ(,) ASSERT_STRNE(,) ASSERT_STRCASEEQ(,) ASSERT_STRCASENE(,)

# Jenkins
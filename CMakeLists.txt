cmake_minimum_required(VERSION 3.1)
project(MatasanoChallenge)

set (CMAKE_CXX_STANDARD 14)
find_package (Threads)

################################
# GTest
################################
enable_testing()

include_directories($ENV{GTEST}/include $ENV{GTEST} /usr/local/include/botan-2)
link_directories($ENV{GTEST}/mybuild /usr/local/lib)

################################
# Unit Tests
################################
# Add test cpp file
add_executable(runUnitTests challenge1/challenge1_test.cpp challenge2/challenge2_test.cpp)

# Link test executable against gtest & gtest_main
target_link_libraries(runUnitTests
                      gtest
                      gtest_main
                      ${CMAKE_THREAD_LIBS_INIT}
                      libbotan-2.a)
                      
add_test( runUnitTests runUnitTests )
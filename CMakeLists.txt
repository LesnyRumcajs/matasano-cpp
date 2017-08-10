cmake_minimum_required(VERSION 3.1)
project(MatasanoChallenge)

set (CMAKE_CXX_STANDARD 14)
find_package (Threads)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

################################
# GTest
################################
enable_testing()

include_directories($ENV{GTEST}/include $ENV{GTEST} /usr/local/include/botan-2)
link_directories($ENV{GTEST}/mybuild /usr/local/lib)

################################
# Unit Tests
################################

add_executable(runChallenge1Test challenge1/challenge1_test.cpp
                                 challenge1/challenge1.cpp
                                 )                            

add_executable(runChallenge2Test challenge2/challenge2_test.cpp
                                 challenge2/challenge2.cpp
                                 )                                                             

# Link test executable against gtest & gtest_main
set(LIBS gtest gtest_main ${CMAKE_THREAD_LIBS_INIT} libbotan-2.a)
target_link_libraries(runChallenge1Test ${LIBS})
target_link_libraries(runChallenge2Test ${LIBS})                   
                      
add_test( runChallenge1Test runChallenge1Test )
add_test( runChallenge2Test runChallenge2Test )
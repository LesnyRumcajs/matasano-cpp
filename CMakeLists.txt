cmake_minimum_required(VERSION 3.1)
project(MatasanoChallenge)

set (CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic")
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
                                 
add_executable(runChallenge3Test challenge3/challenge3_test.cpp
                                 challenge3/challenge3.cpp
                                 challenge2/challenge2.cpp
                                 )
                                 
add_executable(runChallenge4Test challenge4/challenge4_test.cpp
                                 challenge4/challenge4.cpp
                                 challenge3/challenge3.cpp
                                 challenge2/challenge2.cpp
                                 )

add_executable(runChallenge5Test challenge5/challenge5_test.cpp
                                 challenge5/challenge5.cpp
                                 )

set(LIBS gtest gtest_main ${CMAKE_THREAD_LIBS_INIT} libbotan-2.a)
target_link_libraries(runChallenge1Test ${LIBS})
target_link_libraries(runChallenge2Test ${LIBS})                   
target_link_libraries(runChallenge3Test ${LIBS})
target_link_libraries(runChallenge4Test ${LIBS})                   
target_link_libraries(runChallenge5Test ${LIBS})                   

add_test( runChallenge1Test runChallenge1Test )
add_test( runChallenge2Test runChallenge2Test )
add_test( runChallenge3Test runChallenge3Test )
add_test( runChallenge4Test runChallenge4Test )
add_test( runChallenge5Test runChallenge5Test )
cmake_minimum_required(VERSION 3.10)
project(exercise2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

enable_testing()

add_executable(my_test test.cpp UserRegistration.cpp)
target_link_libraries(my_test PRIVATE GTest::gtest GTest::gmock gmock_main)

include(GoogleTest)
gtest_discover_tests(my_test)

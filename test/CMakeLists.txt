cmake_minimum_required(VERSION 3.10)

set(This JsonTests)

set(Sources
    JsonTests.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    Test_JSON
)

add_test(
    NAME ${This}
    COMMAND ${This}
)
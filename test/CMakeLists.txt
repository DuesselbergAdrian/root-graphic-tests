cmake_minimum_required(VERSION 3.10)

# Graphic tutorials
set(GraphicsTest GraphicsTest)
set(GraphicsSources
    GraphicsJsonTests.cpp
)
add_executable(${GraphicsTest} ${GraphicsSources})
target_link_libraries(${GraphicsTest} PUBLIC
    gtest_main
    Test_JSON
)
add_test(
    NAME ${GraphicsTest}
    COMMAND ${GraphicsTest}
)

#Graphs tutorials
set(GraphsTest GraphsTest)
set(GraphsSources
    GraphsJsonTests.cpp 
)
add_executable(${GraphsTest} ${GraphsSources})
target_link_libraries(${GraphsTest} PUBLIC
    gtest_main
    Test_JSON
)
add_test(
    NAME ${GraphsTest}
    COMMAND ${GraphsTest}
)
cmake_minimum_required(VERSION 2.8)
 
find_package(GTest REQUIRED)
find_package(Boost REQUIRED COMPONENTS regex)

include_directories(${GTEST_INCLUDE_DIRS} ${Boost_INCLUDE_DIR})

set(lexer_SRC lexer.cpp)

add_executable(runTests tests.cpp ${lexer_SRC})
target_link_libraries(runTests ${GTEST_LIBRARIES} ${Boost_LIBRARIES} pthread)
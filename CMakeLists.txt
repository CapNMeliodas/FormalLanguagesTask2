cmake_minimum_required(VERSION 3.4)
project(Testing)

set(CMAKE_CXX_STANDARD 11)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(
	algo.cpp
	test.cpp
)

target_link_libraries(RunTests ${GTEST_LIBRARIES} Threads::Threads)

enable_testing()
add_test(Tests RunTests)
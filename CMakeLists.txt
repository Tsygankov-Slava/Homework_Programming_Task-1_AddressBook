cmake_minimum_required(VERSION 3.23)
project(task_1)

set(CMAKE_CXX_STANDARD 20)

#Build googletest
add_subdirectory(
        "${CMAKE_CURRENT_SOURCE_DIR}/googletest"
        "googletest")

#Main target
add_executable(task_1 src/main.cpp src/AddressBook/Employee/Employee.hpp src/AddressBook/AddressBook.cpp src/AddressBook/AddressBook.hpp)

#Test target
add_executable(
        test
        tests/test.cpp)

#Add src to the include directories for the test target
target_include_directories(
        test PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

#Link test target against gtest libraries
target_link_libraries(
        test PRIVATE
        gtest gtest_main
)
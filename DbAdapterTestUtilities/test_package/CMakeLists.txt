cmake_minimum_required(VERSION 3.2)

project(DbAdapterPackageTestProject)

# Configure environment
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../cmake ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Find tested package
find_package(DbAdapterTestUtilities)

# Configure test package project
set(DB_ADAPTER_PACKAGE_TEST_PROJECT DbAdapterPackageTest)
add_executable(${DB_ADAPTER_PACKAGE_TEST_PROJECT} DbAdapterExample.cpp)
target_link_libraries(${DB_ADAPTER_PACKAGE_TEST_PROJECT} DbAdapterTestUtilities::DbAdapterTestUtilities)

# Register tests
enable_testing()
add_test(NAME DbAdapterPackageTest COMMAND ${DB_ADAPTER_PACKAGE_TEST_PROJECT})

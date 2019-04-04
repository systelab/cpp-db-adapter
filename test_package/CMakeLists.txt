cmake_minimum_required(VERSION 3.2)

project(DbAdapterPackageTestProject)

# Configure environment
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../cmake)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Setup up Google test
include(ConfigureGoogleTest)
configure_google_test()

# Setup 3rd party libraries through conan
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# Configure test package project
set(DB_ADAPTER_PACKAGE_TEST_PROJECT DbAdapterPackageTest)
add_executable(${DB_ADAPTER_PACKAGE_TEST_PROJECT} DbAdapterExample.cpp)
target_link_libraries(${DB_ADAPTER_PACKAGE_TEST_PROJECT} gmock_main ${CONAN_LIBS})

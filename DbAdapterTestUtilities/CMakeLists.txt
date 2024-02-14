cmake_minimum_required(VERSION 3.20)

project(DbAdapterTestUtilities)

# Configure environment
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Find external dependencides
find_package(TestUtilitiesInterface REQUIRED)
find_package(DbAdapterInterface REQUIRED)
find_package(GTest REQUIRED)

# Polished project configuration for Visual Studio
IF(MSVC)
    ADD_DEFINITIONS("/EHsc")
ENDIF(MSVC)

# Configure DB Adapter test utilities project
set(DB_ADAPTER_TEST_UTILITIES_PROJECT DbAdapterTestUtilities)
file(GLOB_RECURSE DB_ADAPTER_TEST_UTILITIES_PROJECT_SRC
                  "${PROJECT_SOURCE_DIR}/Comparators/*.cpp"
                  "${PROJECT_SOURCE_DIR}/Mocks/*.cpp"
                  "${PROJECT_SOURCE_DIR}/Stubs/*.cpp")
file(GLOB_RECURSE DB_ADAPTER_TEST_UTILITIES_PROJECT_HDR
                  "${PROJECT_SOURCE_DIR}/Comparators/*.h"
                  "${PROJECT_SOURCE_DIR}/Mocks/*.h"
                  "${PROJECT_SOURCE_DIR}/Stubs/*.h"
                  "${PROJECT_SOURCE_DIR}/stdafx.h")

add_library(${DB_ADAPTER_TEST_UTILITIES_PROJECT} STATIC ${DB_ADAPTER_TEST_UTILITIES_PROJECT_SRC} ${DB_ADAPTER_TEST_UTILITIES_PROJECT_HDR})
target_link_libraries(${DB_ADAPTER_TEST_UTILITIES_PROJECT} GTest::gtest
														   TestUtilitiesInterface::TestUtilitiesInterface
														   DbAdapterInterface::DbAdapterInterface)
					  
# Configure include directories
target_include_directories(${DB_ADAPTER_TEST_UTILITIES_PROJECT} PUBLIC ${PROJECT_SOURCE_DIR}
																PUBLIC ${GTest_INCLUDE_DIRS})

# Configure source groups
foreach(FILE ${DB_ADAPTER_TEST_UTILITIES_PROJECT_SRC} ${DB_ADAPTER_TEST_UTILITIES_PROJECT_HDR})
    get_filename_component(PARENT_DIR "${FILE}" DIRECTORY)
    string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}" "" GROUP "${PARENT_DIR}")
    string(REPLACE "/" "\\" GROUP "${GROUP}")

    if ("${FILE}" MATCHES ".*\\.cpp")
       set(GROUP "Source Files${GROUP}")
    elseif("${FILE}" MATCHES ".*\\.h")
       set(GROUP "Header Files${GROUP}")
    endif()

    source_group("${GROUP}" FILES "${FILE}")
endforeach()

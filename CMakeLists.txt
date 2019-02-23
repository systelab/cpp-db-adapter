cmake_minimum_required(VERSION 3.2)

macro(configure_google_test)
    # Download and unpack googletest at configure time
    configure_file(GoogleTest.in googletest-download/CMakeLists.txt)
    execute_process(COMMAND ${CMAKE_COMMAND} -G ${CMAKE_GENERATOR} .
                    RESULT_VARIABLE result
                    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download)
    if(result)
      message(FATAL_ERROR CMake step for googletest failed ${result})
    endif()

    execute_process(COMMAND ${CMAKE_COMMAND} --build .
                    RESULT_VARIABLE result
                    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download)
    if(result)
      message(FATAL_ERROR Build step for googletest failed ${result})
    endif()

	# Prevent overriding the parent project's compiler/linker settings on Windows
	set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    # Add googletest directly to our build. This defines
    # the gtest and gtest_main targets.
    add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
                     ${CMAKE_BINARY_DIR}/googletest-build
                     EXCLUDE_FROM_ALL)
					 
	# Add GoogleTest to includes
	include_directories("${gtest_SOURCE_DIR}/include")
	include_directories("${gmock_SOURCE_DIR}/include")

	# Include cmake module for GoogleTest
	include(GoogleTest)
endmacro()

macro(configure_test_utilities)
	# Configure repository to clone
	set(TEST_UTILITIES_URL https://github.com/systelab/cpp-test-utilities.git)	
	set(TEST_UTILITIES_DIR extern/TestUtilities)
	set(TEST_UTILITIES_BRANCH master)

	# Check if git is available
	find_package(Git)
	if(NOT GIT_FOUND)
		message(FATAL_ERROR "git not found!")
	endif()

	# Clone the test utilities repository
	if(EXISTS ${CMAKE_SOURCE_DIR}/${TEST_UTILITIES_DIR})
		message(STATUS "${TEST_UTILITIES_DIR} found, pulling...")
		execute_process(
                COMMAND             ${GIT_EXECUTABLE} pull origin master
                COMMAND             ${GIT_EXECUTABLE} submodule update --remote
                WORKING_DIRECTORY   ${CMAKE_SOURCE_DIR}
                OUTPUT_VARIABLE     git_output)
	else()
		message(STATUS "${TEST_UTILITIES_DIR} directory not found, cloning...")
		execute_process(
				COMMAND             ${GIT_EXECUTABLE} clone ${TEST_UTILITIES_URL} ${TEST_UTILITIES_DIR}
				WORKING_DIRECTORY   ${CMAKE_SOURCE_DIR}
				OUTPUT_VARIABLE     git_output)
	endif()
	
	# Checkout the right branch
	message(STATUS "Checking out ${TEST_UTILITIES_BRANCH} branch...")
	execute_process(
			COMMAND             ${GIT_EXECUTABLE} checkout ${TEST_UTILITIES_BRANCH}
			WORKING_DIRECTORY   ${CMAKE_SOURCE_DIR}
			OUTPUT_VARIABLE     git_output)
			
	# Add cloned folder into includes
	include_directories(${CMAKE_SOURCE_DIR}/${TEST_UTILITIES_DIR})	
endmacro()


# Configure project
project(DbAdapter)

# Setup google_test (before set bin dir)
configure_google_test()

# Setup extern repositories
configure_test_utilities()

# Configure include directories
include_directories(${CMAKE_SOURCE_DIR})

# Add subprojects
add_subdirectory(${CMAKE_SOURCE_DIR}/DbAdapterTestUtilities)


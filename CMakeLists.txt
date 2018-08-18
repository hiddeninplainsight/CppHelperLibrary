cmake_minimum_required(VERSION 3.12)
project(CppHelperLibrary)

SET(CMAKE_EXPORT_COMPILE_COMMANDS 1)

set(CMAKE_CXX_STANDARD 14)

if(${UNIX})
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Werror")

	set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -ftest-coverage -fprofile-arcs")
	set(CMAKE_EXE_LINKER_FLAGS_DEBUG "-O0 -g -ftest-coverage -fprofile-arcs -lgcov")

	set(CMAKE_CXX_FLAGS_RELEASE "-O3")
	set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELEASE}")
	set(CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_RELEASE}")
endif()

add_subdirectory(third-party-libraries)
add_subdirectory(src)
add_subdirectory(tests)

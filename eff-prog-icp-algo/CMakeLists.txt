# CMakeList.txt : CMake project for eff-prog-icp-algo, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("eff-prog-icp-algo")

set(CMAKE_CXX_STANDARD 11)
# Set build type if not set.
if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif()
# Set additional flags  when using GCC.
if(CMAKE_COMPILER_IS_GNUCXX)
	# Show all warnings.
	set(CMAKE_CXX_FLAGS "-Wall -Wextra")
	# Keep debug information in binary and do not do any optimizations.
	set(CMAKE_CXX_FLAGS_DEBUG "-g -00")
	# Full optimization in release.
	set(CMAKE_CXX_FLAGS_RELEASE "-03")
endif()

# Set the default path for built executables to the "bin" directory.
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")
# Set the default path for built libraries to the "lib" directory.
set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/lib")

add_subdirectory("${PROJECT_SOURCE_DIR}/src")

# TODO: Add tests and install targets if needed.

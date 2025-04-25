# CMakeList.txt : CMake project for Algorithm-Fundamentals-And-Study, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Algorithm-Fundamentals-And-Study")

# Add source to this project's executable.
add_executable(traversalIndexing		     arrays_strings/basics/traversal_indexing.cpp)
add_executable(reverseSwap					 arrays_strings/basics/reverse_swap.cpp)
add_executable(twoSumSorted					 arrays_strings/two_pointers/opposing_pointers/two_sum_sorted.cpp)
add_executable(twoSumUnsorted				 arrays_strings/two_pointers/opposing_pointers/two_sum_unsorted.cpp)
add_executable(containsWithMostWater		 arrays_strings/two_pointers/opposing_pointers/container_with_most_water.cpp)
add_executable(validPalindrome		 arrays_strings/two_pointers/opposing_pointers/is_palindrome.cpp)
add_executable(reverseString				 arrays_strings/two_pointers/opposing_pointers/reverse_string.cpp)
add_executable(trapRainWater				 arrays_strings/two_pointers/opposing_pointers/trap_rain_water.cpp)

if (CMAKE_VERSION VERSION_GREATER 3.12)
	set(CMAKE_CXX_STANDARD 20)
	set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

# TODO: Add tests and install targets if needed.

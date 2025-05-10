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
add_executable(TraversalIndexing							arrays_strings/basics/traversal_indexing.cpp)
add_executable(ReverseSwap									arrays_strings/basics/reverse_swap.cpp)
add_executable(TwoSumSorted									arrays_strings/two_pointers/opposing_pointers/two_sum_sorted.cpp)
add_executable(TwoSumUnsorted								arrays_strings/two_pointers/opposing_pointers/two_sum_unsorted.cpp)
add_executable(ContainsWithMostWater						arrays_strings/two_pointers/opposing_pointers/container_with_most_water.cpp)
add_executable(ValidPalindrome								arrays_strings/two_pointers/opposing_pointers/is_palindrome.cpp)
add_executable(ReverseString								arrays_strings/two_pointers/opposing_pointers/reverse_string.cpp)
add_executable(TrapRainWater								arrays_strings/two_pointers/opposing_pointers/trap_rain_water.cpp)

add_executable(FindMiddleOfLinkedList						arrays_strings/two_pointers/fast_slow_pointers/find_middle_of_linked_list.cpp)
add_executable(DetectCycleInLinkedList						arrays_strings/two_pointers/fast_slow_pointers/detect_cycle_in_linked_list.cpp)
add_executable(FindCycleStart								arrays_strings/two_pointers/fast_slow_pointers/find_cycle_start.cpp)

add_executable(LongestSubstringWithKDistinct				arrays_strings/sliding_window/longest_substring_with_k_distinct.cpp)
add_executable(MaxSumOfSubarrayFixed						arrays_strings/sliding_window/max_sum_of_subarray_fixed.cpp)
add_executable(MinSubarrayLengthGreaterOrEqualThanTarget	arrays_strings/sliding_window/min_subarray_length_greater_or_equal_than_target.cpp)

add_executable(RangeSumQueryImmutable						arrays_strings/prefix_sum/range_sum_query_immutable.cpp)
add_executable(SubarraySumEqualsK							arrays_strings/prefix_sum/subarray_sum_equals_k.cpp)
add_executable(MaximumSubarraySum							arrays_strings/kadane_algorithm/maximum_subarray_sum.cpp)

add_executable(StandardBinarySearch							searching_sorting/binary_search/standard_binary_search.cpp)
add_executable(SearchInRotatedSortedArray					searching_sorting/binary_search/search_in_rotated_sorted_array.cpp)
add_executable(BinarySearchOnAnswerSpace					searching_sorting/binary_search/binary_search_on_answer_space.cpp)

add_executable(MergeSort									searching_sorting/comparison_based_sorting/merge_sort.cpp)
add_executable(QuickSort									searching_sorting/comparison_based_sorting/quick_sort.cpp)
add_executable(HeapSort										searching_sorting/comparison_based_sorting/heap_sort.cpp)

add_executable(CountingSort									searching_sorting/counting_based_sorting/counting_sort.cpp)
add_executable(RadixSort									searching_sorting/counting_based_sorting/radix_sort.cpp)

add_executable(PreorderTraversal							trees/traversals/preorder_traversal.cpp)
add_executable(InorderTraversal								trees/traversals/inorder_traversal.cpp)
add_executable(PostorderTraversal							trees/traversals/postorder_traversal.cpp)
add_executable(LevelOrderTraversal							trees/traversals/level_order_traversal.cpp)

add_executable(StandardBST									trees/binary_search_tree/search_in_bst.cpp)
add_executable(InsertIntoBST								trees/binary_search_tree/insert_into_bst.cpp)
add_executable(DeleteFromBST								trees/binary_search_tree/delete_from_bst.cpp)

add_executable(HeightOfTree									trees/tree_properties/height_of_tree.cpp)
add_executable(DiameterOfTree								trees/tree_properties/diameter_of_tree.cpp)
add_executable(CheckBalancedTree							trees/tree_properties/check_balanced_tree.cpp)

add_executable(LowestCommonAncestor							trees/advanced_trees/lowest_common_ancestor.cpp)
add_executable(SerializeDeserializeTree						trees/advanced_trees/serialize_deserialize_tree.cpp)
add_executable(TreeMaxPathSum								trees/advanced_trees/binary_tree_max_path_sum.cpp)

if (CMAKE_VERSION VERSION_GREATER 3.12)
	set(CMAKE_CXX_STANDARD 20)
	set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()
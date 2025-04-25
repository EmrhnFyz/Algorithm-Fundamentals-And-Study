# Arrays & Strings

## What?
Arrays are contiguous sequences of elements supporting constant‑time indexed access; strings are arrays of characters used for textual data. These structures form the foundation for many algorithmic patterns.

## When?
Use array and string techniques whenever you need to process or query sequences of values in order, perform random-access operations, or handle subarray/substring problems efficiently.

## Why?
They underpin a wide range of algorithms—from two‑pointer and sliding‑window patterns to prefix‑sum techniques and dynamic programming. Mastering these basics lets you optimize from O(N²) brute‑force to O(N) or O(N log N) solutions.

## Subtopics Covered
1. [**📁 Basics & Pitfalls**](basics)
    - [Traversal & indexing](basics/traversal_indexing.cpp)
    - [In-place swapping & reversing](basics/reverse_swap.cpp)
    - [Pitfall table](basics/pitfall_table.md)
2. [**📁 Two-Pointer Pattern**](two_pointers)
    - [**📁 Opposing pointers**](two_pointers/opposing_pointers)
      - [Container with Most Water](two_pointers/opposing_pointers/container_with_most_water.cpp)
      - [Is Palindrome](two_pointers/opposing_pointers/is_palindrome.cpp)
      - [Reverse String](two_pointers/opposing_pointers/reverse_string.cpp)
      - [Trap Rain Water](two_pointers/opposing_pointers/trap_rain_water.cpp)
      - [Two Sum (Sorted)](two_pointers/opposing_pointers/two_sum_sorted.cpp)
      - [Two Sum (Unsorted)](two_pointers/opposing_pointers/two_sum_unsorted.cpp)
      - [Pattern Overview](two_pointers/opposing_pointers/README.md)
    - [**📁 Fast/slow pointers**](two_pointers/fast_slow_pointers)
       - [Detect Cycle in Linked List](two_pointers/fast_slow_pointers/detect_cycle_in_linked_list.cpp)
       - [Find Cycle Start](two_pointers/fast_slow_pointers/find_cycle_start.cpp)
       - [Find Middle of Linked List](two_pointers/fast_slow_pointers/find_middle_of_linked_list.cpp) 
3. [**📁 Sliding-Window Pattern**](sliding_window)
    - [Longest Substring with K Distinct](sliding_window/longest_substring_with_k_distinct.cpp)
    - [Max Sum of Subarray (Fixed)](sliding_window/max_sum_of_subarray_fixed.cpp)
    - [Min Subarray Length ≥ Target (Variable)](sliding_window/min_subarray_length_greater_or_equal_than_target.cpp)
4. [**📁 Prefix-Sum Technique**](prefix_sum)
    - [Range Sum Query (Immutable)](prefix_sum/range_sum_query_immutable.cpp)
    - [Subarray Sum Equals K](prefix_sum/subarray_sum_equals_k.cpp)
5. [**📁 Kadane’s Algorithm**](kadane_algorithm)
    - [Maximum Subarray Sum](kadane_algorithm/maximum_subarray_sum.cpp)

## Key Takeaways
- **Indexed access**: Arrays/strings allow O(1) element retrieval but watch for off‑by‑one and out‑of‑bounds errors.
- **Two‑pointer** reduces nested loops by converging from ends or using fast/slow scans.
- **Sliding‑window** transforms repeated subarray aggregation into linear-time updates.
- **Prefix‑sum** trades O(N) preprocessing for O(1) range-sum queries—ideal for frequent queries.
- **Kadane’s** leverages local vs. global maxima to find the best subarray without extra memory.
- **Edge cases**: empty arrays, K > N, all negatives, uniform data—always include boundary checks.


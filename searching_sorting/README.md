# Searching & Sorting

## What?
Searching and sorting algorithms are essential for efficiently retrieving, organizing, and processing data. 
They serve as the foundation for countless algorithmic strategies — from binary search to divide‑and‑conquer sorting to optimization techniques.

## When?
Apply searching and sorting whenever you need to:
- Find specific values or conditions within data (searching)
- Reorganize data for easier access, binary search compatibility, or efficient aggregation (sorting)

Common in interview problems involving "search in sorted array", "find minimum", "optimize selection", and "preprocessing before further steps".

## Why?
Efficient search/sort strategies drastically improve runtime:
- **Binary search** cuts problem size by half each step (O(log N)).
- **Efficient sorts** like Merge Sort, Quick Sort, and Heap Sort prepare data for faster searching, comparison, or aggregation tasks.
- Mastery over these patterns unlocks optimization opportunities across almost every problem domain.

## Subtopics Covered
1. [**📁 Binary Search Variations**](binary_search)
    - [Standard Binary Search](binary_search/standard_binary_search.cpp)
    - [Search in Rotated Sorted Array](binary_search/search_in_rotated_sorted_array.cpp)
    - [Binary Search on Answer Space](binary_search/binary_search_on_answer_space.cpp)
2. [**📁 Comparison-Based Sorting**](comparison_sort)
    - [Merge Sort](comparison_sort/merge_sort.cpp)
    - [Quick Sort](comparison_sort/quick_sort.cpp)
    - [Heap Sort](comparison_sort/heap_sort.cpp)
3. [**📁 Counting-Based Sorting**](counting_sort)
    - [Counting Sort](counting_sort/counting_sort.cpp)
    - [Radix Sort](counting_sort/radix_sort.cpp)

## Key Takeaways
- **Binary search** efficiently narrows down sorted search spaces in O(log N) time.
- **Merge Sort** and **Quick Sort** use divide‑and‑conquer to achieve O(N log N) average time for general sorting.
- **Heap Sort** provides sorting with guaranteed O(N log N) time and in-place memory usage.
- **Counting Sort** and **Radix Sort** outperform comparison sorts (O(N)) when input constraints (small ranges, fixed digit lengths) are favorable.
- **Searching optimization**: sometimes we can binary search not the array itself, but the **answer space** (e.g., minimum feasible value).

Mastering search and sort unlocks the ability to efficiently tackle higher-level dynamic programming, greedy optimization, and graph algorithms.

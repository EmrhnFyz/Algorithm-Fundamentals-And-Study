# Searching & Sorting

## What?
Searching and sorting algorithms are fundamental techniques for efficiently **retrieving**, **organizing**, and **optimizing** data.  
They form the basis for countless higher-level strategies — from binary search and divide‑and‑conquer sorting to feasibility optimization.

## When?
Apply searching and sorting techniques when you need to:
- **Find** specific values or satisfy conditions efficiently (searching)
- **Rearrange** data for faster querying, binary search compatibility, or aggregation (sorting)

These patterns frequently appear in problems involving:
- "Search for element/condition in a sorted array"
- "Find minimum/maximum satisfying a constraint"
- "Preprocess data before optimization or selection"

## Why?
Efficient searching and sorting drastically improve runtime:
- **Binary Search** cuts problem size in half each iteration (O(log N)).
- **Efficient Sorts** like Merge Sort, Quick Sort, and Heap Sort prepare data for faster subsequent operations.
- **Counting-based sorts** like Counting Sort and Radix Sort break traditional O(N log N) limits under certain input constraints.

Mastery of these strategies enables optimization across dynamic programming, greedy algorithms, graph problems, and real-world systems.

## Subtopics Covered
1. [**📁 Binary Search Variations**](binary_search)
    - [Standard Binary Search](binary_search/standard_binary_search.cpp) — Find an exact value in a fully sorted array.
    - [Search in Rotated Sorted Array](binary_search/search_in_rotated_sorted_array.cpp) — Identify sorted halves and locate the target accordingly.
    - [Binary Search on Answer Space](binary_search/binary_search_on_answer_space.cpp) — Find the minimum/maximum feasible value via binary search over conceptual answer ranges.
2. [**📁 Comparison-Based Sorting**](comparison_based_sorting)
    - [Heap Sort](comparison_based_sorting/heap_sort.cpp)
    - [Merge Sort](comparison_based_sorting/merge_sort.cpp)
    - [Quick Sort](comparison_based_sorting/quick_sort.cpp)
3. [**📁 Counting-Based Sorting**](counting_sort)
    - [Counting Sort](counting_sort/counting_sort.cpp)
    - [Radix Sort](counting_sort/radix_sort.cpp)

## Key Takeaways
- **Binary Search** efficiently narrows down search spaces in O(log N) time.
- **Merge Sort** and **Quick Sort** use divide-and-conquer for O(N log N) average runtime sorting.
- **Heap Sort** guarantees O(N log N) sorting while operating in-place.
- **Counting Sort** and **Radix Sort** achieve O(N) performance when input size or digit constraints allow.
- **Optimization Insight**: sometimes binary search applies not directly to the array, but to the **space of possible answers** (e.g., minimizing/maximizing a feasible threshold).

Mastering search and sorting patterns unlocks performance improvements across almost every algorithm category and real-world system design.

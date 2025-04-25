# Algorithm Fundamentals and Study

Welcome to **Algorithm Fundamentals and Study**, a curated collection of core algorithmic patterns and techniques in C++. This repository is designed to help you build a solid foundation, prepare for technical interviews, and develop a strong algorithmic skill set.

## 📚 Overview

This project is organized into eleven major topics, each covering essential algorithms and data structures. For each topic, you will find:

- A **What / When / Why** explanation
- Key takeaways and complexity analysis
- Example problems and solutions in C++
- Practical tips and common pitfalls

## 🚀 Getting Started

### 1. **Clone the repository**:
   ```bash
   git clone https://github.com/EmrhnFyz/algorithm-fundamentals-and-study.git
   cd algorithm-fundamentals-and-study
   ```
### 2. **Browse by topic**:
Each folder corresponds to a major topic. Start with the ones most relevant to your goals.
### 3. **Run examples**:
- **Via IDE**:
  - Open your solution or folder in your chosen IDE (e.g., Rider, VS Code, CLion).
  - Build the project or file and click Run. Your IDE will handle compilation and execution.
- **Via command line:**
  - Navigate to the folder containing the C++ file you want to run.
  - Compile the file using:
    ```bash
    g++ -o output_file_name source_file.cpp
    ```
---

## 📂 Topics Covered

### 1. **Arrays & Strings**
    
   - [X] [**Basics & Pitfalls**](arrays_strings/basics)
     - [X] [Traversal & indexing](arrays_strings/basics/traversal_indexing.cpp)
     - [X] [In-place swapping & reversing](arrays_strings/basics/reverse_swap.cpp)
     - [X] [Pitfalls table](arrays_strings/basics/pitfall_table.md)
   - [X] [**Two-Pointer Pattern**](arrays_strings/two_pointers)
     - [X] [**Opposing pointers**](arrays_strings/two_pointers/opposing_pointers)
        - [X] [Container with Most Water](arrays_strings/two_pointers/opposing_pointers/container_with_most_water.cpp)
        - [X] [Is Palindrome](arrays_strings/two_pointers/opposing_pointers/is_palindrome.cpp)
        - [X] [Reverse String](arrays_strings/two_pointers/opposing_pointers/trap_rain_water.cpp)
        - [X] [Trap Rain Water](arrays_strings/two_pointers/opposing_pointers/trap_rain_water.cpp)
        - [X] [Two Sum (Sorted)](arrays_strings/two_pointers/opposing_pointers/two_sum_sorted.cpp)
        - [X] [Two Sum (Unsorted)](arrays_strings/two_pointers/opposing_pointers/two_sum_unsorted.cpp)
        - [X] [Pattern Overview](arrays_strings/two_pointers/opposing_pointers/README.md)
      - [X] [**Fast/slow pointers**](arrays_strings/two_pointers/fast_slow_pointers)
        - [X] [Detect Cycle in Linked List](arrays_strings/two_pointers/fast_slow_pointers/detect_cycle_in_linked_list.cpp)
        - [X] [Find Cycle Start](arrays_strings/two_pointers/fast_slow_pointers/find_cycle_start.cpp)
        - [X] [Find Middle of Linked List](arrays_strings/two_pointers/fast_slow_pointers/find_middle_of_linked_list.cpp)
        - [X] [Pattern Overview](arrays_strings/two_pointers/fast_slow_pointers/README.md)   
   - [X] [**Sliding Window**](arrays_strings/sliding_window)
     - [X] [Longest Substring with K Distinct](arrays_strings/sliding_window/longest_substring_with_k_distinct.cpp)
     - [X] [Max Sum of Subarray (Fixed)](arrays_strings/sliding_window/max_sum_of_subarray_fixed.cpp)
     - [X] [Min Subarray Length ≥ Target (Variable)](arrays_strings/sliding_window/min_subarray_length_greater_or__equal_than_target.cpp)
     - [X] [Pattern Overview](arrays_strings/sliding_window/README.md)
   - [X] [**Prefix Sum**](arrays_strings/prefix_sum)
     - [X] [Range Sum Query (Immutable)](arrays_strings/prefix_sum/range_sum_query_immutable.cpp)
     - [X] [Subarray Sum Equals K](arrays_strings/prefix_sum/subarray_sum_equals_k.cpp)
     - [X] [Pattern Overview](arrays_strings/prefix_sum/README.md)
   - [X] [**Kadane’s Algorithm**](arrays_strings/kadane_algorithm)
     - [X] [Maximum Subarray Sum](arrays_strings/kadane_algorithm/maximum_subarray_sum.cpp)
     - [X] [Pattern Overview](arrays_strings/kadane_algorithm/README.md) 

### 2. **Searching & Sorting**
   - [ ] Binary Search (on sorted arrays, rotated-array search, answer-space search)
   - [ ] Quick Sort, Merge Sort, Heap Sort (divide-and-conquer, in-place vs. extra space)
   - [ ] Counting Sort / Radix Sort (when elements are in a limited range)

### 3. **Linked Lists, Stacks & Queues**
   - [ ] Linked-List Manipulations (reverse list, detect/remove cycle via Floyd’s algorithm)
   - [ ] Monotonic Stack/Queue (next greater element, sliding-window min/max)
   - [ ] Classic Queue Problems (e.g., BFS traversal)

### 4. **Trees & Graphs**
   - [ ] Tree Traversals (pre/in/post-order, level-order)
   - [ ] DFS & BFS (path existence, connected components)
   - [ ] Lowest Common Ancestor (binary lifting, parent-pointer + depth)
   - [ ] Topological Sort (DAG ordering)
   - [ ] Shortest Paths
      - [ ] Dijkstra’s (non-negative weights)
      - [ ] Bellman-Ford (handles negative edges)
      - [ ] Floyd-Warshall (all-pairs)
   - [ ] Minimum Spanning Tree
      - [ ] Kruskal’s + Union-Find
      - [ ] Prim’s (priority-queue)
   - [ ] Union-Find (cycle detection, grouping)

### 5. **Dynamic Programming**
   - [ ] 1D DP (Fibonacci, climbing stairs, coin-change)
   - [ ] 2D DP (knapsack, longest common subsequence, edit distance)
   - [ ] DP on Sequences (LIS, LCS)
   - [ ] DP on Trees (tree-DP, e.g., "binary tree robbery")
   - [ ] Bitmask DP (Traveling Salesman for small N)

### 6. **Greedy Algorithms**
   - [ ] Interval Scheduling / Meeting Rooms
   - [ ] Activity Selection
   - [ ] Fractional Knapsack
   - [ ] Huffman Coding (optimal prefix codes)

### 7. **Hashing & Math**
   - [ ] Hash Tables (frequency counts, two-sum)
   - [ ] Rolling Hash / Rabin-Karp (substring search)
   - [ ] Number Theory (GCD, Sieve of Eratosthenes, modular exponentiation)

### 8. **Advanced Data Structures**
   - [ ] Trie (prefix matching, autocomplete)
   - [ ] Segment Tree / Fenwick Tree (range queries & updates)
   - [ ] Heap / Priority Queue (k-smallest/largest, merging sorted streams)

### 9. **Backtracking & Recursion**
   - [ ] Permutations & Combinations
   - [ ] Subset-Sum / Partition
   - [ ] N-Queens, Sudoku Solver-style constraints

### 10. **Bit Manipulation**
   - [ ] Basic Ops (&, |, ^, \~, shifts)
   - [ ] Common Tricks (popcount, swap w/o temp, power-of-two checks)

### 11. **Game-Dev / Pathfinding (Bonus)**
   - [ ] A\* Search (heuristic-guided shortest path)
   - [ ] Minimax / Alpha-Beta Pruning (two-player game trees)


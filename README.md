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
  - Open your solution or folder in your chosen IDE (e.g., Rider,VS , VS Code, CLion).
  - Build the project or file and click Run. Your IDE will handle compilation and execution.
- **Via command line:**
  - Navigate to the folder containing the C++ file you want to run.
  - Compile the file using:
    ```bash
    g++ -o output_file_name source_file.cpp
    ```
---

## 📂 Topics Covered

### 1. [**📁Arrays & Strings**](arrays_strings)
    
   - [X] [**📁 Basics & Pitfalls**](arrays_strings/basics)
     - [X] [Traversal & indexing](arrays_strings/basics/traversal_indexing.cpp)
     - [X] [In-place swapping & reversing](arrays_strings/basics/reverse_swap.cpp)
     - [X] [Pitfalls table](arrays_strings/basics/pitfall_table.md)
   - [X] [**📁 Two-Pointer Pattern**](arrays_strings/two_pointers)
     - [X] [**📁 Opposing pointers**](arrays_strings/two_pointers/opposing_pointers)
        - [X] [Container with Most Water](arrays_strings/two_pointers/opposing_pointers/container_with_most_water.cpp)
        - [X] [Is Palindrome](arrays_strings/two_pointers/opposing_pointers/is_palindrome.cpp)
        - [X] [Reverse String](arrays_strings/two_pointers/opposing_pointers/trap_rain_water.cpp)
        - [X] [Trap Rain Water](arrays_strings/two_pointers/opposing_pointers/trap_rain_water.cpp)
        - [X] [Two Sum (Sorted)](arrays_strings/two_pointers/opposing_pointers/two_sum_sorted.cpp)
        - [X] [Two Sum (Unsorted)](arrays_strings/two_pointers/opposing_pointers/two_sum_unsorted.cpp)
        - [X] [Pattern Overview](arrays_strings/two_pointers/opposing_pointers/README.md)
      - [X] [**📁 Fast/slow pointers**](arrays_strings/two_pointers/fast_slow_pointers)
        - [X] [Detect Cycle in Linked List](arrays_strings/two_pointers/fast_slow_pointers/detect_cycle_in_linked_list.cpp)
        - [X] [Find Cycle Start](arrays_strings/two_pointers/fast_slow_pointers/find_cycle_start.cpp)
        - [X] [Find Middle of Linked List](arrays_strings/two_pointers/fast_slow_pointers/find_middle_of_linked_list.cpp)
        - [X] [Pattern Overview](arrays_strings/two_pointers/fast_slow_pointers/README.md)   
   - [X] [**📁 Sliding Window**](arrays_strings/sliding_window)
     - [X] [Longest Substring with K Distinct](arrays_strings/sliding_window/longest_substring_with_k_distinct.cpp)
     - [X] [Max Sum of Subarray (Fixed)](arrays_strings/sliding_window/max_sum_of_subarray_fixed.cpp)
     - [X] [Min Subarray Length ≥ Target (Variable)](arrays_strings/sliding_window/min_subarray_length_greater_or_equal_than_target.cpp)
     - [X] [Pattern Overview](arrays_strings/sliding_window/README.md)
   - [X] [**📁 Prefix Sum**](arrays_strings/prefix_sum)
     - [X] [Range Sum Query (Immutable)](arrays_strings/prefix_sum/range_sum_query_immutable.cpp)
     - [X] [Subarray Sum Equals K](arrays_strings/prefix_sum/subarray_sum_equals_k.cpp)
     - [X] [Pattern Overview](arrays_strings/prefix_sum/README.md)
   - [X] [**📁 Kadane’s Algorithm**](arrays_strings/kadane_algorithm)
     - [X] [Maximum Subarray Sum](arrays_strings/kadane_algorithm/maximum_subarray_sum.cpp)
     - [X] [Pattern Overview](arrays_strings/kadane_algorithm/README.md) 

### 2. [**📁 Searching & Sorting**](searching_sorting)
   - [X] [**📁 Binary Search**](searching_sorting/binary_search)
     - [X] [Standard Binary Search](searching_sorting/binary_search/standard_binary_search.cpp)
     - [X] [Search in Rotated Sorted Array](searching_sorting/binary_search/search_in_rotated_sorted_array.cpp)
     - [X] [Binary Search on Answer Space](searching_sorting/binary_search/binary_search_on_answer_space.cpp)
   - [X] [**📁 Comparison-Based Sorting**](searching_sorting/comparison_based_sorting)
     - [X] [Heap Sort](searching_sorting/comparison_based_sorting/heap_sort.cpp)
     - [X] [Merge Sort](searching_sorting/comparison_based_sorting/merge_sort.cpp)
     - [X] [Quick Sort](searching_sorting/comparison_based_sorting/quick_sort.cpp)
   - [X] [**📁 Counting-Based Sorting**](searching_sorting/counting_based_sorting)
     - [X] [Counting Sort](searching_sorting/counting_based_sorting/counting_sort.cpp)
     - [X] [Radix Sort](searching_sorting/counting_based_sorting/radix_sort.cpp)

  ### 3. [**📁 Trees**](trees_graphs)
   - [X] [**📁 Tree Traversals**](trees/traversals)
     - [X] [Pre-order Traversal (DFS)](trees/traversals/preorder_traversal.cpp)
     - [X] [In-order Traversal (DFS)](trees/traversals/inorder_traversal.cpp)
     - [X] [Post-order Traversal (DFS)](trees/traversals/postorder_traversal.cpp)
     - [X] [Level-order Traversal (BFS)](trees/traversals/level_order_traversal.cpp)
   - [X] [**📁 Binary Search Trees (BST)**](trees/binary_search_tree)
     - [X] [Search in BST](trees/binary_search_tree/search_in_bst.cpp)
     - [X] [Insert into BST](trees/binary_search_tree/insert_into_bst.cpp)
     - [X] [Delete from BST](trees/binary_search_tree/delete_from_bst.cpp)
   - [X] [**📁 Tree Properties**](trees/tree_properties)
     - [X] [Height/Depth of Tree](trees/tree_properties/height_of_tree.cpp)
     - [X] [Diameter of Tree](trees/tree_properties/diameter_of_tree.cpp)
     - [X] [Balanced Tree Check](trees/tree_properties/check_balanced_tree.cpp)
   - [X] [**📁 Advanced Tree Problems**](trees/advanced_trees)
     - [X] [Lowest Common Ancestor (LCA)](trees/advanced_trees/lowest_common_ancestor.cpp)
     - [X] [Serialize and Deserialize Tree](trees/advanced_trees/serialize_deserialize_tree.cpp)
     - [X] [Binary Tree Maximum Path Sum](trees/advanced_trees/binary_tree_max_path_sum.cpp)

### 4. [**📁 Graphs**](graphs)
   - [X] [**📁 Graph Traversals**](graphs/graph_traversals)
     - [X] [Depth-First Search(DFS)](graphs/graph_traversals/dfs_graph.cpp)
     - [X] [Breadth-First Search(BFS)](graphs/graph_traversals/dfs_graph.cpp)
     - [X] [Connected Components (Undirected Graph)](graphs/graph_traversals/connected_components.cpp)
   - [X] [**📁 Topological Sort**](graphs/topological_sort)
     - [X] [Kahn's Algorithm](graphs/topological_sort/kahn_toposort.cpp) 
   - [X] [**📁 Shortest Paths**](graphs/shortest_paths)
     - [X] [Dijkstra's Algorithm](graphs/shortest_paths/dijkstra.cpp)
     - [X] [Bellman-Ford Algorithm](graphs/shortest_paths/bellman_ford.cpp) 
     - [X] [Floyd-Warshall Algorithm](graphs/shortest_paths/floyd_warshall.cpp)
   - [X] [**📁 Minimum Spanning Tree**](graphs/minimum_spanning_tree)
     - [X] [Kruskal's Algorithm](graphs/minimum_spanning_tree/kruskal.cpp)
     - [X] [Prim's Algorithm](graphs/minimum_spanning_tree/prim.cpp)
   - [X] [**📁 Union Find**](graphs/union_find)
     - [X] [Union Find(Basic Find + Union usage)](graphs/union_find/union_find.cpp)
     - [X] [Union Find(Union by Rank optimization)](graphs/union_find/union_by_rank.cpp)
     - [X] [Path Compression](graphs/union_find/path_compression.cpp)
     - [X] [Cycle Detection](graphs/union_find/cycle_detection.cpp) 
       
### 5. **Linked Lists, Stacks & Queues**
   - [ ] Linked-List Manipulations (reverse list, detect/remove cycle via Floyd’s algorithm)
   - [ ] Monotonic Stack/Queue (next greater element, sliding-window min/max)
   - [ ] Classic Queue Problems (e.g., BFS traversal)
   
### 6. **Dynamic Programming**
   - [ ] 1D DP (Fibonacci, climbing stairs, coin-change)
   - [ ] 2D DP (knapsack, longest common subsequence, edit distance)
   - [ ] DP on Sequences (LIS, LCS)
   - [ ] DP on Trees (tree-DP, e.g., "binary tree robbery")
   - [ ] Bitmask DP (Traveling Salesman for small N)

### 7. **Greedy Algorithms**
   - [ ] Interval Scheduling / Meeting Rooms
   - [ ] Activity Selection
   - [ ] Fractional Knapsack
   - [ ] Huffman Coding (optimal prefix codes)

### 8. **Hashing & Math**
   - [ ] Hash Tables (frequency counts, two-sum)
   - [ ] Rolling Hash / Rabin-Karp (substring search)
   - [ ] Number Theory (GCD, Sieve of Eratosthenes, modular exponentiation)

### 9. **Advanced Data Structures**
   - [ ] Trie (prefix matching, autocomplete)
   - [ ] Segment Tree / Fenwick Tree (range queries & updates)
   - [ ] Heap / Priority Queue (k-smallest/largest, merging sorted streams)

### 10. **Backtracking & Recursion**
   - [ ] Permutations & Combinations
   - [ ] Subset-Sum / Partition
   - [ ] N-Queens, Sudoku Solver-style constraints

### 11. **Bit Manipulation**
   - [ ] Basic Ops (&, |, ^, \~, shifts)
   - [ ] Common Tricks (popcount, swap w/o temp, power-of-two checks)

### 12. **Game-Dev / Pathfinding (Bonus)**
   - [ ] A\* Search (heuristic-guided shortest path)
   - [ ] Minimax / Alpha-Beta Pruning (two-player game trees)


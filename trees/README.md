# Trees

## What?
A tree is a **hierarchical data structure** made of nodes, where each node points to one or more children and has exactly one parent (except the root).

Trees are a **special case of graphs** — they are **acyclic** and **connected**.

Common types include:
- Binary Tree (each node has at most two children)
- Binary Search Tree (BST)
- Balanced Trees (AVL, Red-Black)
- Specialized Trees (Tries, Segment Trees, etc.)

## When?
Use trees when:
- Data has a hierarchical structure (e.g., folders, UI components, game scenes).
- You need to perform fast **search, insert, delete** operations (BSTs).
- You need efficient range queries and updates (segment trees, binary indexed trees).

Very common in:
- Recursive problems
- Divide and conquer algorithms
- Searching, optimization, compression, parsing

## Why?
Trees provide:
- **Fast lookup, insertion, deletion** (e.g., O(log n) for balanced BSTs)
- **Efficient storage** of hierarchical data
- **Powerful recursive properties** (every subtree is itself a tree)

They unlock efficient algorithms for many hard problems:
- Searching
- Shortest paths
- Memory management
- Auto-complete systems
- Parsing expressions (syntax trees)

## How?

Many tree algorithms rely on **recursive depth-first traversal**:
- Pre-order (root -> left -> right)
- In-order (left -> root -> right)
- Post-order (left -> right -> root)

And some rely on **breadth-first traversal**:
- Level-order (visit all nodes level by level using a queue)

Trees are naturally recursive: solving a problem on a node often involves solving the same problem on its children.


## Subtopics Covered
1. [**📁 Traversal Algorithms**](traversals)
    - [Pre-order Traversal (DFS)](traversals/preorder_traversal.cpp)
    - [In-order Traversal (DFS)](traversals/inorder_traversal.cpp)
    - [Post-order Traversal (DFS)](traversals/postorder_traversal.cpp)
    - [Level-order Traversal (BFS)](traversals/level_order_traversal.cpp)
    - [Traversal Algorithms Walkthrough](traversals/README.md)
2. [**📁 Binary Search Trees (BST)**](binary_search_tree)
    - [Search in BST](binary_search_tree/search_in_bst.cpp)
    - [Insert into BST](binary_search_tree/insert_into_bst.cpp)
    - [Delete from BST](binary_search_tree/delete_from_bst.cpp)
    - [Binary Search Tree Walkthrough](binary_search_tree/README.md)]
3. [**📁 Tree Properties**](tree_properties)
    - [Height/Depth of Tree](tree_properties/height_of_tree.cpp)
    - [Diameter of Tree](tree_properties/diameter_of_tree.cpp)
    - [Balanced Tree Check](tree_properties/check_balanced_tree.cpp)
    - [Tree Property Explanations](tree_properties/README.md)]
4. [**📁 Advanced Tree Problems**](advanced_trees)
    - [Lowest Common Ancestor (LCA)](advanced_trees/lowest_common_ancestor.cpp)
    - [Serialize and Deserialize Tree](advanced_trees/serialize_deserialize_tree.cpp)
    - [Binary Tree Maximum Path Sum](advanced_trees/binary_tree_max_path_sum.cpp)

## Key Takeaways
- Trees are recursive by nature — most problems are best solved using recursion or stacks/queues.
- Traversals (Preorder, Inorder, Postorder, Level Order) form the basis for almost all tree operations.
- Binary Search Trees enable **O(log n)** average search, insertion, and deletion.
- Tree depth, balance, and paths are critical properties in optimization.
- Mastering trees unlocks skills in graph theory, dynamic programming on trees, and system design.

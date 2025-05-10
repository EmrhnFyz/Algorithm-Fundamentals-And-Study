# Tree Properties

Tree properties are metrics or structural conditions that describe the **shape and behavior of a tree**.  
Understanding these helps with balancing, optimizing, and validating trees in algorithmic problems.

---

## 🌳 Example Tree

```
     1
    / \
   2   3
  /     \
 4       5
          \
           6
```


---

## Core Properties

| Property    | Description                                                                   | Link                                               |
|-------------|-------------------------------------------------------------------------------|----------------------------------------------------|
| **Height**   | Number of edges on the longest path from the root to a leaf                  | [height_of_tree.cpp](height_of_tree.cpp)           |
| **Diameter** | Longest path (in edges) between **any two nodes** in the tree                | [diameter_of_tree.cpp](diameter_of_tree.cpp)       |
| **Balanced** | A tree is balanced if **no subtree is deeper than its sibling by > 1 level** | [check_balanced_tree.cpp](check_balanced_tree.cpp) |

---

## 📏 Key Concepts

### ▸ Height vs Depth

- **Height of a node** = longest downward path to a leaf (measured in edges)
- **Depth of a node** = number of edges from the root to that node

Example:
- Height of root = 3  
- Depth of leaf node = depends on path from root

---

### 🟡 Balanced Tree ≠ Perfect Tree

> A balanced tree doesn't have to be “full” or “perfect.”

This is balanced:

```
    1
   / \
  2   3
 /
4
```


- The left subtree is deeper than the right by **1 level** — this is OK.
- As long as **no node has children that differ in height by more than 1**, it’s considered **balanced**.

A **perfect tree**, in contrast, must have all levels fully filled.

---

## 🧠 Key Takeaways

- **Height** is foundational for many tree algorithms (balance, diameter, DP).
- **Diameter** can pass through any node, not just root.
- **Balanced** trees keep operations efficient by limiting depth skew.
- These properties appear **frequently in interviews**, especially for:
  - Tree traversal validation
  - Lowest common ancestor (LCA)
  - AVL balancing, Red-Black trees
---

# Advanced Tree Problems

These problems build upon foundational tree knowledge (traversals, properties, BSTs) and explore more **recursive, dynamic, and structural challenges**.

They often appear in high-level interviews and system-level applications like:
- Game state saving (serialize trees)
- Path finding (max path sum)
- Graph ancestry and tracing (LCA)

---

## Problems Covered

| Problem                          | Description                                                                       | Link                                                             |
|----------------------------------|-----------------------------------------------------------------------------------|------------------------------------------------------------------|
| **Lowest Common Ancestor (LCA)** | Find the deepest common ancestor of two nodes (doesn’t need to pass through root) | [lowest_common_ancestor.cpp](lowest_common_ancestor.cpp)         |
| **Serialize / Deserialize Tree** | Convert a binary tree to string and back (used in data storage, transmission)     | [serialize_deserialize_tree.cpp](serialize_deserialize_tree.cpp) |
| **Max Path Sum**                 | Find the highest-valued path in the tree (can start and end anywhere)             | [binary_tree_max_path_sum.cpp](binary_tree_max_path_sum.cpp)     |

---

## 🧩 When Should You Use These?

| Use Case                           | Technique to Reach For                 |
|------------------------------------|----------------------------------------|
| Path computation (sum, max length) | Post-order recursion with max tracking |
| Saving/loading trees               | Preorder serialization + null markers  |
| Tree-based ancestry or hierarchy   | LCA with recursive descent             |

---

## 💡 Concepts to Master

- **Post-order recursion**: Think bottom-up, especially when computing returnable gains or structural aggregates.
- **Null handling in serialization**: Always include null markers to maintain structure when rebuilding trees.
- **Propagating vs. using values**: What you compute at a node and what you *return* to the parent are often different!

---

## 🌳 Key Takeaways

- These problems require **careful thinking about recursion boundaries**.
- Many advanced questions mix **traversals + memoization** or **global tracking**.
---

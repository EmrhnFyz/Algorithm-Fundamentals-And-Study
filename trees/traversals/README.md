# Tree Traversals

Tree traversal means visiting all the nodes of a tree in a specific order.  
There are two major categories:
- **Depth-First Traversals** (Preorder, Inorder, Postorder)
- **Breadth-First Traversal** (Level Order)

---

## 🌳 Example Tree

We’ll use this tree for all examples:
```
    1
   / \
  2   3
 / \
4   5
```

---

## 🔁 Traversal Orders

| Traversal Type | Visit Order               | Output                |
|----------------|---------------------------|------------------------|
| **Preorder**    | Root → Left → Right       | `1 2 4 5 3`            |
| **Inorder**     | Left → Root → Right       | `4 2 5 1 3`            |
| **Postorder**   | Left → Right → Root       | `4 5 2 3 1`            |
| **Level Order** | Top to bottom, left to right (BFS) | `1 2 3 4 5`    |

---

## 📦 Preorder Traversal
- Visit current node first (root)
- Traverse left subtree
- Traverse right subtree

- Steps: 1 → 2 → 4 → 5 → 3

📎 [Code → preorder_traversal.cpp](preorder_traversal.cpp)

---

## 📦 Inorder Traversal
- Traverse left subtree
- Visit current node
- Traverse right subtree

Steps: 4 → 2 → 5 → 1 → 3


📎 [Code → inorder_traversal.cpp](inorder_traversal.cpp)

---

## 📦 Postorder Traversal
- Traverse left subtree
- Traverse right subtree
- Visit current node

Steps: 4 → 5 → 2 → 3 → 1


📎 [Code → postorder_traversal.cpp](postorder_traversal.cpp)

---

## 📦 Level Order Traversal (BFS)
- Visit nodes level by level, left to right
- Use a queue (FIFO structure)

Steps: 1 → 2 → 3 → 4 → 5


📎 [Code → level_order_traversal.cpp](level_order_traversal.cpp)

---

## 🧠 Key Takeaways
- **Recursive traversals** (pre/in/post) are great for top-down or bottom-up logic.
- **Inorder traversal of a BST** gives sorted order.
- **Level order traversal** uses a queue and is used in shortest path and multi-level problems.
- Most tree problems can be reduced to one of these four traversal patterns.

Understanding traversal is the first step to mastering tree problems — from search, depth, symmetry, to dynamic programming on trees.

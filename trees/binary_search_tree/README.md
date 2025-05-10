# Binary Search Trees (BST)

A **Binary Search Tree (BST)** is a binary tree where every node follows this rule:

> For any node with value `X`, all values in the left subtree are `< X`,  
> and all values in the right subtree are `> X`.

This ordering enables **efficient searching, insertion, and deletion** operations in **O(log n)** time (for balanced trees).

---

## 🌳 Example BST

```
     6
   /   \
  3     8
 / \     \
2   5     9
```


---

## 🛠 Core Operations

| Operation     | Description                                      | Link                                   |
|---------------|--------------------------------------------------|----------------------------------------|
| **Search**     | Locate a value by recursively going left/right   | [search_in_bst.cpp](search_in_bst.cpp) |
| **Insert**     | Add a new value in the correct BST position      | [insert_into_bst.cpp](insert_into_bst.cpp) |
| **Delete**     | Remove a node (handle 0, 1, or 2 children cases) | [delete_from_bst.cpp](delete_from_bst.cpp) |

---

## 📌 When to Use BSTs?

- When you want fast search, insert, and delete (better than arrays or lists)
- For dynamic datasets where ordering matters
- For implementing sets, maps, and interval trees
- As building blocks in more advanced trees (AVL, Red-Black, Segment Tree)

---

## 💡 Why Use a BST?

- Average time complexity:  
  - **Search/Insert/Delete** → O(log n) (balanced)  
  - Worst case: O(n) (degenerate/skewed)

- **Inorder traversal** of a BST always gives a **sorted sequence**  
- Easy to implement and extend into more powerful data structures

---

## 🧠 Key Takeaways

- Use **recursive logic** to implement most BST operations
- **Duplicates are usually ignored** or handled explicitly
- **Balance is important** — a skewed BST loses performance
- Mastering basic BSTs prepares you for AVL, Red-Black, Treaps, and more

Binary Search Trees are the go-to structure for **ordered, dynamic data** — simple, powerful, and extendable.

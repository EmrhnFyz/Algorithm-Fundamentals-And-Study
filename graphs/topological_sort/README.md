# Topological Sort

## What?

Topological Sort is a **linear ordering of vertices** in a **Directed Acyclic Graph (DAG)** such that for every directed edge `u -> v`, vertex `u` comes before `v` in the ordering.

> ✅ Only valid for DAGs (Directed Acyclic Graphs). If the graph has a cycle, topological sort is not possible.

---

## When?

Use Topological Sort when:
- You want to schedule tasks with dependencies.
- You need to order compilation steps, build systems, or workflows.
- Solving problems like course scheduling, prerequisite resolution, etc.

---

## How?

There are two main approaches:

---

### 🧠 **1. Kahn’s Algorithm (BFS-based)**

**Idea:**
- Compute in-degrees of all nodes.
- Initialize a queue with all nodes having in-degree 0.
- Repeatedly remove from queue and reduce in-degrees of neighbors.
- If a neighbor’s in-degree becomes 0, add it to the queue.

**Steps:**
1. Count in-degrees for all nodes.
2. Add all nodes with in-degree 0 to a queue.
3. While the queue is not empty:
   - Pop a node.
   - Add to result.
   - Reduce in-degree of its neighbors.
   - If any neighbor’s in-degree becomes 0, add it to the queue.

**Complexity:**
- Time: `O(V + E)`
- Space: `O(V)`

**Pros:**
- Simple, intuitive.
- Detects cycles (if result doesn't include all nodes, there is a cycle).

---

### 🌲 **2. DFS-based Topological Sort**

**Idea:**
- Perform DFS traversal.
- After visiting all descendants of a node, push it onto a stack.
- Reverse the stack to get the topological order.

**Steps:**
1. Initialize `visited[]` array.
2. For each unvisited node, perform DFS:
   - Visit neighbors recursively.
   - After all neighbors are visited, push current node to the stack.
3. After all nodes are processed, pop from the stack to get topological order.

**Complexity:**
- Time: `O(V + E)`
- Space: `O(V)`

**Pros:**
- Recursive and elegant.
- Easier to implement if you're already familiar with DFS.

---

## 🔍 Example DAG

```
5 -> 0 ← 4
↓ ↑
2 -> 3 -> 1
```


Possible Topological Orders:
- `4 5 2 3 1 0`
- `5 2 3 1 4 0`
- `5 4 0 2 3 1`  
*(Topological orders are not unique)*

---

## 🚧 Pitfalls

- **Cycles:** If a graph has a cycle, **topological sort fails**.
- **Disconnected Graph:** Ensure you start DFS/BFS from *all* nodes, not just one.
- **Multiple Valid Orders:** Be aware there's no single correct order.

---

## ✅ Implementations

| Algorithm | File |
|----------|------|
| Kahn's Algorithm (BFS) | [`kahn_toposort.cpp`](./kahn_toposort.cpp) |
| DFS-based Toposort     | [`dfs_toposort.cpp`](./dfs_toposort.cpp) |

---

## 🧠 Key Takeaways

- Topological sorting is a **must-know** for DAG-related problems.
- Use **Kahn’s Algorithm** when you want explicit cycle detection.
- Use **DFS-based approach** for recursive elegance and post-order logic.

---

## 📚 More Practice
Try implementing:
- Course Schedule I & II (LeetCode)
- Alien Dictionary
- Parallel Course Scheduling
- Build System Dependency Resolver

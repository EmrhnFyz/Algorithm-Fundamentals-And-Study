# Minimum Spanning Tree (MST)

## What?

A **Minimum Spanning Tree (MST)** is a subset of edges that connects **all nodes** in a **connected, undirected weighted graph** with:
- The **minimum possible total edge weight**
- **No cycles**

MSTs are used in:
- Network design (e.g., laying cables, pipelines)
- Clustering algorithms
- Approximation algorithms for NP-hard problems

---

## When?

Use MST algorithms when:
- You need to connect all components of a network at **minimal cost**
- The graph is **undirected and connected**
- You don’t need shortest paths, but a **spanning structure**

---

## How?

There are two classical MST algorithms:

---

### 🪓 Kruskal’s Algorithm (Greedy, Edge-based)

**Idea:**
- Sort all edges by weight.
- Use **Union-Find** (Disjoint Set Union) to track connected components.
- For each edge, if it connects two separate components, include it in the MST.

**Complexity:**
- Time: `O(E log E)` (sorting) + `O(E * α(V))` (DSU operations)
- Space: `O(V)`
- Best for **edge list** representation and sparse graphs

✅ Very efficient for sparse graphs  
⚠️ Requires Union-Find for cycle detection

📄 [kruskal.cpp](./kruskal.cpp)

---

### 🧲 Prim’s Algorithm (Greedy, Node-based)

**Idea:**
- Start from an arbitrary node.
- Use a **min-heap** to always select the smallest edge connecting a visited node to an unvisited node.
- Expand the MST by adding the lightest edge at each step.

**Complexity:**
- Time: `O(E log V)` with a priority queue
- Space: `O(V + E)`
- Best for **dense graphs** or adjacency list/matrix input

✅ Easy to implement with heaps  
⚠️ Can be slower than Kruskal on edge list-based graphs

📄 [prim.cpp](./prim.cpp)

---

## 🔍 Example Graph

```
0 - 1 (10)
| \
6  5
|
2 - 3 (4)
|
15
```


MST could include:
- 2 — 3 (4)
- 0 — 3 (5)
- 0 — 1 (10)  
**Total weight = 19**

---

## ⚠️ Pitfalls

| Pitfall                      | How to Handle									|
|------------------------------|------------------------------------------------|
| Duplicate edges (undirected) | Add both directions if using adj list			|
| Disconnected graph           | MST requires connectivity						|
| Cycles                       | Use Union-Find (Kruskal) or visited set (Prim) |
| Wrong priority queue usage   | Always push the **lowest weight edge** next	|

---

## 🧠 Key Takeaways

- Both Kruskal and Prim are **greedy** algorithms for MST.
- **Kruskal** is better for **edge lists**, **Prim** shines on **dense graphs**.
- Union-Find is a vital concept in Kruskal’s algorithm.

---

## 📚 Further Reading

- LeetCode: [1135. Connecting Cities With Minimum Cost](https://leetcode.com/problems/connecting-cities-with-minimum-cost/)
- LeetCode: [1584. Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points/)
- HackerRank: [Kruskal (MST): Really Special Subtree](https://www.hackerrank.com/challenges/kruskalmstrsub/problem)


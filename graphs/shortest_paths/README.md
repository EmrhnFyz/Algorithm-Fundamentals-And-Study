# Shortest Path Algorithms

## What?

Shortest Path algorithms help us find the **minimum distance** between nodes in a graph.  
These are crucial for navigation, route planning, network optimization, and many real-world systems.

---

## When?

Use Shortest Path algorithms when:
- You need to calculate the minimum cost/time/distance between points.
- You work with **weighted graphs** (non-uniform costs).
- You must handle **negative weights** or detect **negative cycles**.

---

## How?

### Dijkstra's Algorithm (Single-Source, Non-Negative Weights)

**Use case:** Fastest way from a source to all other nodes (e.g. GPS navigation).  
**Key Features:**
- Uses a **min-heap (priority queue)** to greedily choose the closest unvisited node.
- **Fails** with negative weights (may return incorrect results).

**Complexity:**
- Time: `O((V + E) log V)`
- Space: `O(V)`

✅ Fast and efficient for dense graphs with **non-negative weights**.

📄 [dijkstra.cpp](./dijkstra.cpp)

---

### Bellman-Ford Algorithm (Single-Source, Handles Negatives)

**Use case:** Same as Dijkstra, but also detects **negative-weight cycles**.  
**Key Features:**
- Repeatedly "relaxes" edges `V - 1` times.
- Final pass checks for further relaxation to detect cycles.

**Complexity:**
- Time: `O(V * E)`
- Space: `O(V)`

✅ Works with **negative weights**, but slower than Dijkstra.  
⚠️ Can detect negative cycles.

📄 [bellman_ford.cpp](./bellman_ford.cpp)

---

### Floyd-Warshall Algorithm (All-Pairs, Dynamic Programming)

**Use case:** Find **shortest path between every pair of nodes**.  
**Key Features:**
- Dynamic Programming approach.
- Handles **negative weights**.
- Can detect **negative-weight cycles** by checking if `dist[i][i] < 0`.

**Complexity:**
- Time: `O(V³)`
- Space: `O(V²)`

✅ Best when you need **all-pairs shortest paths**.  
⚠️ Not suitable for huge graphs due to `O(V³)` time.

📄 [floyd_warshall.cpp](./floyd_warshall.cpp)

---

## 🔍 Example Graph (Used Across Algorithms)

```
0 → 1 (3)
0 → 2 (6)
1 → 2 (4)
1 → 3 (4)
2 → 3 (8)
3 → 0 (varies per test)
```


- When `3 → 0 = -10`, the graph contains a **negative cycle** (Floyd-Warshall will report it).
- When `3 → 0 = 5`, the graph is safe and all algorithms will compute valid paths.

---

## ⚠️ Pitfalls to Watch For

| Algorithm        | Handles Negative Weights  | Detects Negative Cycles   | Use Case                   |
|------------------|---------------------------|---------------------------|----------------------------|
| Dijkstra         | ❌                        | ❌                       | Fast paths, no negatives   |
| Bellman-Ford     | ✅                        | ✅                       | Slow but robust            |
| Floyd-Warshall   | ✅                        | ✅                       | All-pairs, dense graphs    |

---

## 🧠 Key Takeaways

- Use **Dijkstra** for fast, non-negative graphs.
- Use **Bellman-Ford** for robustness and cycle detection.
- Use **Floyd-Warshall** when you need **all-pairs shortest paths**.

---

## 🧩 Further Reading

- LeetCode: [743. Network Delay Time](https://leetcode.com/problems/network-delay-time/)
- LeetCode: [787. Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/)
- LeetCode: [1334. Find the City With the Smallest Number of Neighbors](https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/)


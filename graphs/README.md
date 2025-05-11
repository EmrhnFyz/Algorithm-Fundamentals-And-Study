# Graphs

## What?
A graph is a collection of **nodes (vertices)** and **edges** that connect pairs of nodes.  
Graphs can be:
- **Directed or undirected**
- **Weighted or unweighted**
- **Cyclic or acyclic**
- **Connected or disconnected**

Graphs generalize trees and appear in a vast range of problems — from pathfinding to dependency resolution.

Common types:
- Adjacency list or matrix representations
- Directed Acyclic Graphs (DAGs)
- Trees (a subtype of graph)
- Weighted graphs for shortest path or MST algorithms

---

## When?
Use graphs when:
- You need to model **relationships or connections** (networks, maps, dependencies)
- You're working with **reachability**, **shortest paths**, or **cyclic dependencies**
- Tree structure isn’t enough (e.g. multiple parents, loops, directed edges)

Very common in:
- Pathfinding
- Social networks
- Scheduling and ordering (topological sort)
- Web crawling
- Flow algorithms

---

## Why?
Graphs enable:
- **Generalized connectivity** — many real-world problems naturally form graphs
- Efficient modeling of:
    - **Paths** (BFS, DFS, Dijkstra)
    - **Cycles and dependencies** (Union-Find, Topo Sort)
    - **Component grouping** (DFS, Union-Find)
    - **Optimized traversal** (BFS for shortest path in unweighted, Dijkstra for weighted)

---

## How?

Most graph algorithms use:
- **Breadth-First Search (BFS)** for shortest path in unweighted graphs
- **Depth-First Search (DFS)** for cycle detection, connected components, topological sort
- **Priority queues** for Dijkstra’s algorithm
- **Union-Find (Disjoint Set)** for MSTs, grouping, or cycle detection
- **Dynamic Programming** on DAGs

Graph representations:
- **Adjacency List** (most common): efficient for sparse graphs
- **Adjacency Matrix**: efficient for dense graphs or constant-time edge lookup

---

## Subtopics Covered

1. [**📁 Graph Traversals**](graph_traversals)
    - [Breadth-First Search (BFS)](graph_traversals/bfs.cpp)
    - [Depth-First Search (DFS)](graph_traversals/dfs.cpp)
    - [Connected Components (Undirected)](graph_traversals/connected_components.cpp)
2. [**📁 Topological Sort**](topo_sort)
    - [Kahn’s Algorithm (BFS)](topo_sort/kahn_toposort.cpp)
    - [DFS-based Topo Sort](topo_sort/dfs_toposort.cpp)
3. [**📁 Shortest Paths**](shortest_paths)
    - [Dijkstra's Algorithm](shortest_paths/dijkstra.cpp)
    - [Bellman-Ford Algorithm](shortest_paths/bellman_ford.cpp)
    - [Floyd-Warshall (All-Pairs)](shortest_paths/floyd_warshall.cpp)
4. [**📁 Minimum Spanning Tree (MST)**](mst)
    - [Prim’s Algorithm](mst/prim.cpp)
    - [Kruskal’s Algorithm](mst/kruskal.cpp)
5. [**📁 Union-Find (Disjoint Set)**](union_find)
    - [Cycle Detection](union_find/cycle_detection.cpp)
    - [Union by Rank + Path Compression](union_find/optimized_union_find.cpp)

---

## Key Takeaways

- **Graphs model real-world relationships** where tree-like hierarchy is insufficient.
- BFS and DFS are the foundation for almost all graph algorithms.
- Topological sort helps when processing **ordering with dependencies** (e.g., build systems).
- Dijkstra, Bellman-Ford, and Floyd-Warshall cover **single- and all-pair shortest paths**.
- MSTs are crucial for **network design** (min-cost connection).
- Union-Find is fast and elegant for **grouping and cycle detection**.

Graphs appear in nearly every advanced algorithm problem space —  
mastering them unlocks **real-world problem solving**, from web crawling to game AI to compiler design.

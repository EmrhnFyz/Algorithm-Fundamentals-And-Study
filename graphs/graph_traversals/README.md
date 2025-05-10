# Graph Traversals

Graph traversal is the foundation of nearly every graph algorithm.  
It’s how we **explore**, **search**, and **analyze** connections between nodes.

---

## 🔁 BFS vs DFS

| Traversal | Type          | Typical Use Cases                              | Data Structure    |
|-----------|---------------|------------------------------------------------|-------------------|
| **BFS**   | Breadth-First | Shortest path in unweighted graphs, levels     | Queue             |
| **DFS**   | Depth-First   | Cycle detection, component grouping, topo sort | Stack / Recursion |

Both traverse all reachable nodes, but in different orders:
- **BFS** visits nodes **level-by-level**
- **DFS** dives **deep before backtracking**

---

## 📦 Problems Covered

| Problem                               | Description                                               | Link                                                 |
|---------------------------------------|-----------------------------------------------------------|------------------------------------------------------|
| **Breadth-First Search (BFS)**        | Visit all nodes starting from source, layer by layer      | [bfs.cpp](bfs.cpp)                                   |
| **Depth-First Search (DFS)**          | Recursively visit as deep as possible before backtracking | [dfs.cpp](dfs.cpp)                                   |
| **Connected Components (Undirected)** | Count and label distinct groups in an undirected graph    | [connected_components.cpp](connected_components.cpp) |

---

## 🧠 Key Concepts

- **Visited array**: Avoid revisiting nodes (and infinite loops)
- **Adjacency list**: Efficient structure for sparse graphs
- **Component count**: Each DFS from an unvisited node starts a new component
- **Traversal order**: Depends on BFS (queue) vs DFS (stack)

---

## 📌 Real-World Use Cases

- **BFS**: Social networks (shortest connection path), unweighted navigation
- **DFS**: File systems, maze solving, connected regions in grids
- **Component detection**: Isolated clusters, network segmentation

---
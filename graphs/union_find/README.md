# Union-Find (Disjoint Set Union)

## What?

**Union-Find** (or **Disjoint Set Union**) is a data structure that keeps track of elements split into disjoint sets.

It supports two key operations:
- `Find(x)`: Determine the representative (root) of the set that contains `x`
- `Union(x, y)`: Merge the sets that contain `x` and `y`

---

## When?

Use Union-Find when:
- You need to **track connectivity** between elements
- You want to **detect cycles** in undirected graphs
- You’re solving **MST problems** (e.g. Kruskal’s Algorithm)
- You’re grouping things (like islands, components, labels, etc.)

---

## How?

Union-Find works best with two critical optimizations:

### Union by Rank (or Size)
- Attach the smaller tree under the larger one
- Prevents the tree from becoming tall

### Path Compression
- During `Find()`, point each node directly to the root
- Greatly flattens the tree structure

When used together, operations run in **near constant time** `O(α(N))` — where `α` is the inverse Ackermann function.

---

## ✅ Implementations

| File                                             | What it Demonstrates                                   |
|--------------------------------------------------|--------------------------------------------------------|
| [`union_find.cpp`](./union_find.cpp)             | Basic Find + Union usage                               |
| [`union_by_rank.cpp`](./union_by_rank.cpp)       | Union by Rank optimization                             |
| [`path_compression.cpp`](./path_compression.cpp) | Path compression visualization with tree flattening    |
| [`cycle_detection.cpp`](./cycle_detection.cpp)   | Using Union-Find to detect cycles in undirected graphs |

---

## 📌 Core Concepts

### Find with Path Compression

```cpp
int Find(int node) {
	if (parent[node] != node)
		parent[node] = Find(parent[node]);
	return parent[node];
}
```
### Union by Rank

```cpp
void Union(int a, int b) {
	int rootA = Find(a);
	int rootB = Find(b);

	if (rootA == rootB) return;

	if (rank[rootA] < rank[rootB]) {
		parent[rootA] = rootB;
	} else if (rank[rootA] > rank[rootB]) {
		parent[rootB] = rootA;
	} else {
		parent[rootB] = rootA;
		rank[rootA]++;
	}
}
```

### Key Use Cases

- Kruskal’s MST Algorithm
- Detecting cycles in an undirected graph
- Dynamic connectivity (are x and y in the same group?)
- Group labeling in grid/graph problems (e.g., islands)

### ⚠️ Pitfalls

| Mistake                                 | Fix                                                   |
| --------------------------------------- | ----------------------------------------------------- |
| Using Union-Find in **directed** graphs | It only works naturally for **undirected** components |
| Not applying **path compression**       | You’ll get poor performance on long chains            |
| Forgetting to initialize parents        | Always set `parent[i] = i` in constructor             |


### 📚 Further Reading
- LeetCode: 547. Number of Provinces
- LeetCode: 1319. Number of Operations to Make Network Connected
- LeetCode: 990. Satisfiability of Equality Equations
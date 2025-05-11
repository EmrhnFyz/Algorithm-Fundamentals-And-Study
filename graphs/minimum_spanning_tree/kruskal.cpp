/*
	Problem: Minimum Spanning Tree (Kruskal's Algorithm)

	Given an undirected, connected graph with weighted edges,
	find a subset of edges that connects all nodes with the minimum total weight
	and contains no cycles (i.e., a Minimum Spanning Tree).

	----------------------------------------------------
	Idea:
	- Sort all edges by weight.
	- Initialize Disjoint Set (Union-Find) to track connected components.
	- For each edge (u, v) in sorted order:
		- If u and v are in different sets, add the edge to MST.
		- Union their sets.

	Learning Highlights:
	- Time Complexity: O(E log E) for sorting + O(E * α(N)) for union-find
	- Space Complexity: O(N)
	- Greedy algorithm
	- Best for edge list-based graphs
	----------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <__msvc_ostream.hpp>

using namespace std;

// Structure to represent a weighted undirected edge
struct Edge
{
	int from;
	int to;
	int weight;

	// Comparator to sort edges by weight (ascending)
	bool operator<(const Edge& other) const
	{
		return weight < other.weight;
	}
};

// Disjoint Set Union (Union-Find) with path compression and union by rank
class DisjointSet
{
	vector<int> parent;
	vector<int> rank;

public:
	DisjointSet(int size)
	{
		parent.resize(size);
		rank.resize(size, 0);

		// Initially, every node is its own parent (self root)
		for (int i = 0; i < size; ++i)
			parent[i] = i;
	}

	// Find the representative (root) of a node with path compression
	int Find(int node)
	{
		if (parent[node] != node)
		{
			parent[node] = Find(parent[node]);
		}

		return parent[node];
	}

	// Union the sets of two nodes. Return false if they’re already connected.
	bool Union(int a, int b)
	{
		int rootA = Find(a);
		int rootB = Find(b);

		if (rootA == rootB)
		{
			return false; // Already in the same set — would form a cycle
		}

		// Union by rank: attach smaller tree under larger
		if (rank[rootA] < rank[rootB])
		{
			parent[rootA] = rootB;
		}
		else if (rank[rootA] > rank[rootB])
		{
			parent[rootB] = rootA;
		}
		else
		{
			parent[rootB] = rootA;
			rank[rootA]++;
		}
		return true;
	}
};

int KruskalMST(int nodeCount, vector<Edge>& edges)
{
	// Sort all edges in increasing order of weight
	sort(edges.begin(), edges.end());

	// Initialize disjoint set for cycle detection
	DisjointSet dsu(nodeCount);

	int totalWeight = 0;

	cout << "Edges in the Minimum Spanning Tree:\n";
	for (const Edge& edge : edges)
	{
		// If including this edge doesn't form a cycle
		if (dsu.Union(edge.from, edge.to))
		{
			cout << edge.from << " - " << edge.to << " (weight " << edge.weight << ")\n";
			totalWeight += edge.weight;
		}
	}
	return totalWeight;
}

int main()
{
	/*
		Graph:
		0 - 1 (10)
		0 - 2 (6)
		0 - 3 (5)
		1 - 3 (15)
		2 - 3 (4)

		MST:
		2 - 3 (4)
		0 - 3 (5)
		0 - 1 (10)
		Total: 19
	*/

	int nodeCount = 4;
	vector<Edge> edges = {
		{0, 1, 10},
		{0, 2, 6},
		{0, 3, 5},
		{1, 3, 15},
		{2, 3, 4}
	};

	int total = KruskalMST(nodeCount, edges);
	cout << "Total weight of MST: " << total << endl;

	return 0;
}

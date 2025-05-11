/*
	Problem: Cycle Detection in an Undirected Graph (using Union-Find)

	Given an undirected graph, determine whether it contains a cycle.

	----------------------------------------------------
	Idea:
	- Use Union-Find to group connected nodes into sets.
	- For each edge (u, v):
		- If u and v are in the same set -> a cycle exists.
		- Otherwise, union them into one set.

	Learning Highlights:
	- Time Complexity: O(E * α(N)) — nearly linear with path compression
	- Space Complexity: O(N)
	- Works for undirected graphs
	----------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <utility>
#include <__msvc_ostream.hpp>

using namespace std;

class DisjointSet
{
	vector<int> parent;
	vector<int> rank;

public:
	DisjointSet(int size)
	{
		parent.resize(size);
		rank.resize(size, 0);
		for (int i = 0; i < size; ++i)
		{
			parent[i] = i;
		}
	}

	int Find(int node)
	{
		if (parent[node] != node)
		{
			parent[node] = Find(parent[node]);
		}
		return parent[node];
	}

	bool Union(int a, int b)
	{
		int rootA = Find(a);
		int rootB = Find(b);

		if (rootA == rootB)
			return false; // Already connected -> cycle

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

// Returns true if there is a cycle in the undirected graph
bool ContainsCycle(int nodeCount, const vector<pair<int, int>>& edges)
{
	DisjointSet dsu(nodeCount);

	for (const auto& [u, v] : edges)
	{
		if (!dsu.Union(u, v))
		{
			// u and v are already connected -> cycle found
			return true;
		}
	}
	return false;
}

int main()
{
	/*
		Graph 1 (No cycle):
		0 - 1
		1 - 2
		2 - 3

		Graph 2 (Has cycle):
		0 - 1
		1 - 2
		2 - 0
	*/

	vector<pair<int, int>> graph1 = {
		{0, 1}, {1, 2}, {2, 3}
	};

	vector<pair<int, int>> graph2 = {
		{0, 1}, {1, 2}, {2, 0}
	};

	cout << "Graph 1 contains cycle? " << (ContainsCycle(4, graph1) ? "Yes" : "No") << endl;
	cout << "Graph 2 contains cycle? " << (ContainsCycle(3, graph2) ? "Yes" : "No") << endl;

	return 0;
}

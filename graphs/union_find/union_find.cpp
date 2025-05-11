/*
	Problem: Disjoint Set Union (Union-Find)

	The Disjoint Set (Union-Find) data structure keeps track of elements partitioned
	into disjoint (non-overlapping) sets. Supports two main operations:
	- Find: Determine which set a particular element belongs to
	- Union: Merge two sets

	----------------------------------------------------
	Idea:
	- Each element starts in its own set.
	- Use an array to track parent links.
	- Use path compression in Find to flatten trees.
	- Use union by rank to keep trees shallow.

	Learning Highlights:
	- Time Complexity (amortized): O(α(N)) — inverse Ackermann, nearly constant
	- Space Complexity: O(N)
	- Used in Kruskal’s algorithm, cycle detection, grouping/labeling problems
	----------------------------------------------------
*/

#include <iostream>
#include <vector>
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

		// Initially, each node is its own parent
		for (int i = 0; i < size; ++i)
		{
			parent[i] = i;
		}
	}

	// Find the representative (root) of a node with path compression
	int Find(int node)
	{
		if (parent[node] != node)
		{
			parent[node] = Find(parent[node]); // Path compression
		}

		return parent[node];
	}

	// Union the sets of two nodes by rank
	bool Union(int a, int b)
	{
		int rootA = Find(a);
		int rootB = Find(b);

		if (rootA == rootB)
		{
			return false; // Already in the same set
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

	// Check whether two nodes are in the same set
	bool Connected(int a, int b)
	{
		return Find(a) == Find(b);
	}
};

int main()
{
	/*
		Disjoint sets:
		Initially: {0}, {1}, {2}, {3}, {4}

		After unions:
		Union(0, 1) -> {0, 1}
		Union(2, 3) -> {2, 3}
		Union(1, 3) -> {0, 1, 2, 3}

		Final sets: {0,1,2,3}, {4}
	*/

	DisjointSet dsu(5);

	dsu.Union(0, 1);
	dsu.Union(2, 3);
	dsu.Union(1, 3);

	cout << "Are 0 and 3 connected? " << (dsu.Connected(0, 3) ? "Yes" : "No") << endl;
	cout << "Are 0 and 4 connected? " << (dsu.Connected(0, 4) ? "Yes" : "No") << endl;

	return 0;
}

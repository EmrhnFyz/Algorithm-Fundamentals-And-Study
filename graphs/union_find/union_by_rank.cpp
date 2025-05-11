/*
	Problem: Union-Find with Union by Rank and Path Compression

	This is a focused demonstration of how Union by Rank and Path Compression
	optimize the Union-Find data structure to near-constant time complexity.

	----------------------------------------------------
	Idea:
	- Path Compression: Flattens the tree during Find to reduce depth.
	- Union by Rank: Attaches the smaller tree under the larger one during Union.
	- Together they give almost O(1) performance per operation (amortized).

	Learning Highlights:
	- Time Complexity: O(α(N)) per operation (inverse Ackermann)
	- Space Complexity: O(N)
	- Core technique in MST (Kruskal), dynamic connectivity, cycle detection
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

		for (int i = 0; i < size; ++i)
		{
			parent[i] = i;
		}
	}

	int Find(int node)
	{
		if (parent[node] != node)
		{
			parent[node] = Find(parent[node]); // Path compression
		}

		return parent[node];
	}

	void Union(int a, int b)
	{
		int rootA = Find(a);
		int rootB = Find(b);

		if (rootA == rootB)
			return; // Already connected

		// Union by rank
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
	}

	void PrintSets(int size)
	{
		for (int i = 0; i < size; ++i)
		{
			cout << "Node " << i << " is in set: " << Find(i) << endl;
		}
	}
};

int main()
{
	DisjointSet dsu(6);

	dsu.Union(0, 1);
	dsu.Union(1, 2);
	dsu.Union(3, 4);
	dsu.Union(4, 5);
	dsu.Union(2, 5); // Connect both components

	cout << "Final sets:\n";
	dsu.PrintSets(6);

	return 0;
}

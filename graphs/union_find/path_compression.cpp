/*
	Problem: Path Compression in Union-Find

	Path Compression is a key optimization that flattens the tree during Find operations,
	improving the efficiency of future queries by pointing nodes directly to the root.

	This demonstration builds two trees:
	- A deep chain (3 -> 2 -> 1 -> 0) which will be compressed
	- A second component (6 -> 5 -> 4) that remains uncompressed for contrast

	----------------------------------------------------
	Idea:
	- Manually build trees to control structure
	- Apply Find(3) to trigger compression
	- Compare parent relationships before and after

	Learning Highlights:
	- Time Complexity (amortized): O(α(N)), nearly constant
	- Space Complexity: O(N)
	- Core for MST, dynamic connectivity, and group tracking
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

	// Find with optional verbose logging for compression trace
	int Find(int node, bool verbose = false)
	{
		if (parent[node] != node)
		{
			if (verbose)
			{
				cout << "Compressing path for node " << node << endl;
			}
			parent[node] = Find(parent[node], verbose); // Path compression
		}
		return parent[node];
	}

	// Manually assign parent (used to build specific chains)
	void UnionRaw(int child, int parentNode)
	{
		parent[child] = parentNode;
	}

	// Print current parent relationships
	void PrintParents()
	{
		for (int i = 0; i < parent.size(); ++i)
		{
			cout << "Node " << i << " -> Parent: " << parent[i] << endl;
		}
	}
};

int main()
{
	DisjointSet dsu(7);

	// Manually build two chains:
	// Chain A: 3 -> 2 -> 1 -> 0
	dsu.UnionRaw(3, 2);
	dsu.UnionRaw(2, 1);
	dsu.UnionRaw(1, 0);

	// Chain B: 6 -> 5 -> 4 (no compression will be applied here)
	dsu.UnionRaw(6, 5);
	dsu.UnionRaw(5, 4);

	cout << "--- Before path compression ---\n";
	dsu.PrintParents();

	// Trigger compression only for one chain
	cout << "\nCalling Find(3)... (this will compress path in Chain A)\n";
	dsu.Find(3, true); // Apply Find with verbose output

	cout << "\n--- After path compression ---\n";
	dsu.PrintParents();

	return 0;
}

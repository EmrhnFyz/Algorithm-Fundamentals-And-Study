/*
	Problem: Minimum Spanning Tree (Prim's Algorithm)

	Given a weighted undirected graph, find a subset of edges that connects all nodes
	with the minimum total weight and no cycles (i.e., a Minimum Spanning Tree).

	----------------------------------------------------
	Idea:
	- Start from any node (e.g., node 0).
	- Use a min-heap (priority queue) to always select the edge with the smallest weight.
	- Keep adding the smallest valid edge that connects a new node to the MST.
	- Stop when all nodes are included in the MST.

	Learning Highlights:
	- Time Complexity: O(E log V) with priority queue
	- Space Complexity: O(V + E)
	- Greedy algorithm
	- Best for adjacency list or matrix representations
	----------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <__msvc_ostream.hpp>

using namespace std;

typedef pair<int, int> WeightedEdge; // (weight, neighbor)

int PrimMST(int nodeCount, const vector<vector<WeightedEdge>>& adjacencyList)
{
	vector<bool> visited(nodeCount, false);          // Track which nodes are in MST
	priority_queue<WeightedEdge, vector<WeightedEdge>, greater<>> minHeap; // Min-heap for edges

	int totalWeight = 0;
	minHeap.push({ 0, 0 }); // (weight, start node)

	while (!minHeap.empty())
	{
		auto [weight, currentNode] = minHeap.top();
		minHeap.pop();

		// Skip if already included
		if (visited[currentNode])
		{
			continue;
		}

		visited[currentNode] = true;
		totalWeight += weight;

		// Add all edges from currentNode to heap
		for (const auto& [neighbor, edgeWeight] : adjacencyList[currentNode])
		{
			if (!visited[neighbor])
			{
				minHeap.push({ edgeWeight, neighbor });
			}
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
	vector<vector<WeightedEdge>> adjacencyList(nodeCount);

	// Add undirected edges
	adjacencyList[0].push_back({ 1, 10 });
	adjacencyList[1].push_back({ 0, 10 });

	adjacencyList[0].push_back({ 2, 6 });
	adjacencyList[2].push_back({ 0, 6 });

	adjacencyList[0].push_back({ 3, 5 });
	adjacencyList[3].push_back({ 0, 5 });

	adjacencyList[1].push_back({ 3, 15 });
	adjacencyList[3].push_back({ 1, 15 });

	adjacencyList[2].push_back({ 3, 4 });
	adjacencyList[3].push_back({ 2, 4 });

	int total = PrimMST(nodeCount, adjacencyList);
	cout << "Total weight of MST: " << total << endl;

	return 0;
}

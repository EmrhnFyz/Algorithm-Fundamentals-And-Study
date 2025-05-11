/*
	Problem: Single-Source Shortest Path (Dijkstra's Algorithm)

	Given a weighted directed graph and a source node, find the shortest path
	from the source to all other nodes. Edge weights are non-negative.

	----------------------------------------------------
	Idea:
	- Use a min-heap (priority queue) to always pick the next closest node.
	- Initialize all distances as infinite, except the source (distance 0).
	- For each node, update its neighbors if a shorter path is found via it.
	- Push updated neighbors back into the heap.

	Learning Highlights:
	- Time Complexity: O((V + E) log V)
	- Space Complexity: O(V)
	- Works with graphs having non-negative edge weights
	- Efficient and widely used in real-world navigation/pathfinding problems
	----------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// WeightedEdge represents a pair of (distance, neighbor)
typedef pair<int, int> WeightedEdge;

vector<int> DijkstraShortestPath(int nodeCount, const vector<vector<WeightedEdge>>& adjacencyList, int source)
{
	// Initialize distances with infinity
	vector<int> shortestDistances(nodeCount, INT_MAX);

	// Min-heap to pick the node with the smallest known distance
	priority_queue<WeightedEdge, vector<WeightedEdge>, greater<>> minHeap;

	// Distance to source is 0
	shortestDistances[source] = 0;
	minHeap.push({ 0, source });

	while (!minHeap.empty())
	{
		// Extract the node with the smallest known distance
		auto [currentDistance, currentNode] = minHeap.top();
		minHeap.pop();

		// If this entry is outdated, skip it
		if (currentDistance > shortestDistances[currentNode])
		{
			continue;
		}

		// Visit all neighbors of the current node
		for (const auto& [neighbor, weight] : adjacencyList[currentNode])
		{
			// Calculate new potential distance to neighbor
			int newDistance = shortestDistances[currentNode] + weight;

			// If the new distance is shorter, update it
			if (newDistance < shortestDistances[neighbor])
			{
				shortestDistances[neighbor] = newDistance;
				minHeap.push({ newDistance, neighbor }); // Push updated distance
			}
		}
	}

	return shortestDistances;
}

int main()
{
	/*
		Graph:
		0 --(4)--> 1
		0 --(1)--> 2
		2 --(2)--> 1
		1 --(1)--> 3
		2 --(5)--> 3

		Shortest paths from node 0:
		Node 0: 0
		Node 1: 3
		Node 2: 1
		Node 3: 4
	*/

	int nodeCount = 4;
	vector<vector<WeightedEdge>> adjacencyList(nodeCount);

	adjacencyList[0].push_back({ 1, 4 });
	adjacencyList[0].push_back({ 2, 1 });
	adjacencyList[2].push_back({ 1, 2 });
	adjacencyList[1].push_back({ 3, 1 });
	adjacencyList[2].push_back({ 3, 5 });

	int sourceNode = 0;
	vector<int> shortestDistances = DijkstraShortestPath(nodeCount, adjacencyList, sourceNode);

	// Output the shortest distances
	cout << "Shortest distances from node " << sourceNode << ":\n";
	for (int node = 0; node < nodeCount; ++node)
	{
		cout << "Node " << node << ": ";
		if (shortestDistances[node] == INT_MAX)
		{
			cout << "unreachable";
		}
		else
		{
			cout << shortestDistances[node];
		}
		cout << "\n";
	}

	return 0;
}

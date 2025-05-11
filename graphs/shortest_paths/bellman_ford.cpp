/*
	Problem: Single-Source Shortest Path (Bellman-Ford Algorithm)

	Given a weighted directed graph (which may contain negative weights),
	find the shortest distance from a source node to all other nodes.
	If a negative-weight cycle exists, report it.

	----------------------------------------------------
	Idea:
	- Initialize all distances to ∞, except the source (set to 0).
	- Relax all edges (V - 1) times:
		For each edge u -> v with weight w:
			if dist[u] + w < dist[v], update dist[v]
	- After V - 1 relaxations, do one more pass:
		If any edge can still be relaxed, a negative cycle exists.

	Learning Highlights:
	- Time Complexity: O(V * E)
	- Space Complexity: O(V)
	- Handles negative weights
	- Can detect negative-weight cycles (unlike Dijkstra)
	----------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <climits>
#include <__msvc_ostream.hpp>

using namespace std;

struct Edge
{
	int from;
	int to;
	int weight;
};

vector<int> BellmanFordShortestPath(int nodeCount, const vector<Edge>& edges, int source)
{
	vector<int> distances(nodeCount, INT_MAX);
	distances[source] = 0;

	// Step 1: Relax all edges (nodeCount - 1) times
	for (int i = 0; i < nodeCount - 1; ++i)
	{
		for (const Edge& edge : edges)
		{
			if (distances[edge.from] != INT_MAX && distances[edge.from] + edge.weight < distances[edge.to])
			{
				distances[edge.to] = distances[edge.from] + edge.weight;
			}
		}
	}

	// Step 2: Check for negative-weight cycles
	for (const Edge& edge : edges)
	{
		if (distances[edge.from] != INT_MAX && distances[edge.from] + edge.weight < distances[edge.to])
		{
			cout << "Negative-weight cycle detected. Shortest path not defined." << endl;
			return {};
		}
	}

	return distances;
}

int main()
{
	/*
		Graph:
		0 -> 1 (weight 4)
		0 -> 2 (weight 5)
		1 -> 2 (weight -3)
		2 -> 3 (weight 3)

		Shortest paths from node 0:
		Node 0: 0
		Node 1: 4
		Node 2: 1
		Node 3: 4
	*/

	int nodeCount = 4;
	vector<Edge> edges = {
		{0, 1, 4},
		{0, 2, 5},
		{1, 2, -3},
		{2, 3, 3}
	};

	int sourceNode = 0;
	vector<int> shortestDistances = BellmanFordShortestPath(nodeCount, edges, sourceNode);

	if (!shortestDistances.empty())
	{
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
	}

	return 0;
}

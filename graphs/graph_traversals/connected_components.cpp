/*
	Problem: Count Connected Components in an Undirected Graph

	Given an undirected graph represented by an adjacency list,
	find the number of connected components.

	----------------------------------------------------
	Idea:
	- Use DFS to visit all nodes in a component.
	- Keep a visited array to avoid revisiting.
	- For each unvisited node, start a DFS — this marks a new component.

	Learning Highlights:
	- Time Complexity: O(V + E)
	- Space Complexity: O(V) for visited[] + recursion stack
	----------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <__msvc_ostream.hpp>
using namespace std;

void Dfs(int node, const vector<vector<int>>& adj, vector<bool>& visited)
{
	visited[node] = true;

	for (int neighbor : adj[node])
	{
		if (!visited[neighbor])
		{
			Dfs(neighbor, adj, visited);
		}
	}
}

int CountConnectedComponents(int n, const vector<vector<int>>& adj)
{
	vector<bool> visited(n, false);
	int count = 0;

	for (int i = 0; i < n; ++i)
	{
		if (!visited[i])
		{
			Dfs(i, adj, visited);
			count++; // new component found
		}
	}

	return count;
}

// Sample graph builder
vector<vector<int>> BuildSampleGraph(int& n)
{
	/*
		Graph (5 nodes, 3 components):
		0 - 1       2       3 - 4

		Component 1: 0, 1
		Component 2: 2
		Component 3: 3, 4
	*/
	n = 5;
	vector<vector<int>> adj(n);
	adj[0].push_back(1);
	adj[1].push_back(0);
	adj[3].push_back(4);
	adj[4].push_back(3);
	return adj;
}

int main()
{
	int n;
	vector<vector<int>> adj = BuildSampleGraph(n);

	int components = CountConnectedComponents(n, adj);
	cout << "Number of connected components: " << components << endl;

	return 0;
}

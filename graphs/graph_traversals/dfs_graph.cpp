/*
	Problem: Depth-First Search (DFS) in an Undirected Graph

	Given a graph represented as an adjacency list, perform DFS traversal
	starting from a given node. Print all visited nodes.

	----------------------------------------------------
	Idea:
	- Use a recursive function to visit a node and all its unvisited neighbors.
	- Maintain a visited[] array or set to prevent infinite loops.

	Learning Highlights:
	- Time Complexity: O(V + E) for adjacency list
	- Space Complexity: O(V) for visited + recursion stack
	----------------------------------------------------
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
using namespace std;

// DFS recursive function
void dfs(int node, unordered_map<int, vector<int>>& graph, unordered_set<int>& visited)
{
	if (visited.count(node)) return;

	visited.insert(node);
	cout << node << " ";  // Visit the node

	for (int neighbor : graph[node])
	{
		dfs(neighbor, graph, visited);
	}
}

int main()
{
	// Graph represented as an adjacency list
	unordered_map<int, vector<int>> graph;

	/*
		Graph structure:
		0 — 1
		|   |
		2 — 3

		DFS from 0 -> possible output: 0 1 3 2
	*/
	graph[0] = { 1, 2 };
	graph[1] = { 0, 3 };
	graph[2] = { 0, 3 };
	graph[3] = { 1, 2 };

	unordered_set<int> visited;
	cout << "DFS traversal starting from node 0: ";
	dfs(0, graph, visited);
	cout << endl;

	return 0;
}

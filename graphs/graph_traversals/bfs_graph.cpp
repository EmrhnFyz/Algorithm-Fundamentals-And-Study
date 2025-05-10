/*
	Problem: Breadth-First Search (BFS) in an Undirected Graph

	Given a graph represented as an adjacency list, perform BFS traversal
	starting from a given node. Print all visited nodes in BFS order.

	----------------------------------------------------
	Idea:
	- Use a queue to explore neighbors level by level.
	- Mark nodes as visited when enqueued (not dequeued!).

	Learning Highlights:
	- Time Complexity: O(V + E)
	- Space Complexity: O(V) for visited and queue
	----------------------------------------------------
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;

void bfs(int startNode, unordered_map<int, vector<int>>& graph)
{
	unordered_set<int> visited;
	queue<int> q;

	visited.insert(startNode);
	q.push(startNode);

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		cout << node << " ";  // Visit the node

		for (int neighbor : graph[node])
		{
			if (!visited.count(neighbor))
			{
				visited.insert(neighbor);
				q.push(neighbor);
			}
		}
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

		BFS from 0 → 0 1 2 3 (order may vary by adjacency list)
	*/
	graph[0] = { 1, 2 };
	graph[1] = { 0, 3 };
	graph[2] = { 0, 3 };
	graph[3] = { 1, 2 };

	cout << "BFS traversal starting from node 0: ";
	bfs(0, graph);
	cout << endl;

	return 0;
}

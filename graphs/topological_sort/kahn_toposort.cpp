/*
	Problem: Topological Sort (Kahn’s Algorithm)

	Given a directed acyclic graph (DAG), return a topological ordering of its nodes.
	A topological order is a linear sequence where for every directed edge u -> v,
	node u comes before v in the order.

	----------------------------------------------------
	Idea:
	- Count in-degrees for all nodes.
	- Add all nodes with in-degree 0 to a queue.
	- While the queue is not empty:
		- Remove a node, add to result
		- Reduce in-degree of its neighbors
		- If any neighbor’s in-degree drops to 0, add it to the queue

	Learning Highlights:
	- Time Complexity: O(V + E)
	- Space Complexity: O(V)
	- Works only for DAGs (must check for cycle if topological sort fails)
	----------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <queue>
#include <__msvc_ostream.hpp>
using namespace std;

vector<int> KahnToposort(int n, const vector<vector<int>>& adj)
{
	vector<int> inDegree(n, 0);
	vector<int> result;

	// Step 1: Count in-degrees
	for (int u = 0; u < n; ++u)
	{
		for (int v : adj[u])
		{
			inDegree[v]++;
		}
	}

	// Step 2: Queue for nodes with in-degree 0
	queue<int> q;
	for (int i = 0; i < n; ++i)
	{
		if (inDegree[i] == 0)
		{
			q.push(i);
		}
	}

	// Step 3: Process queue
	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		result.push_back(curr);

		for (int neighbor : adj[curr])
		{
			inDegree[neighbor]--;
			if (inDegree[neighbor] == 0)
			{
				q.push(neighbor);
			}
		}
	}

	// Optional: cycle check
	if (result.size() != n)
	{
		cout << "Cycle detected! Topological sort not possible." << endl;
		return {};
	}

	return result;
}

// Sample DAG(Directed Acyclic Graphs) builder
vector<vector<int>> BuildSampleGraph(int& n)
{
	/*
		DAG:
		5 -> 0 ← 4
		↓
		2 -> 3
		↑
		1

		One valid topological order: 4 5 0 2 3 1
	*/
	n = 6;
	vector<vector<int>> adj(n);
	adj[5].push_back(0);
	adj[5].push_back(2);
	adj[4].push_back(0);
	adj[2].push_back(3);
	adj[3].push_back(1);
	return adj;
}

int main()
{
	int n;
	vector<vector<int>> adj = BuildSampleGraph(n);

	vector<int> topoOrder = KahnToposort(n, adj);

	if (!topoOrder.empty())
	{
		cout << "Topological order: ";
		for (int node : topoOrder)
		{
			cout << node << " ";
		}
		cout << endl;
	}

	return 0;
}

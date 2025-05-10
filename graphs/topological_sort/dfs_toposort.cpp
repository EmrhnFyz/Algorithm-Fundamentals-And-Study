#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph
{
	int V; // Number of vertices
	vector<vector<int>> adj;

	void DFS(int v, vector<bool>& visited, stack<int>& Stack)
	{
		visited[v] = true;

		for (int neighbor : adj[v])
		{
			if (!visited[neighbor])
			{
				DFS(neighbor, visited, Stack);
			}
		}

		// Push current vertex to stack after visiting all its neighbors
		Stack.push(v);
	}

public:
	Graph(int V)
	{
		this->V = V;
		adj.resize(V);
	}

	void AddEdge(int u, int v)
	{
		adj[u].push_back(v); // Directed edge from u to v
	}

	void TopologicalSort()
	{
		vector<bool> visited(V, false);
		stack<int> Stack;

		for (int i = 0; i < V; ++i)
		{
			if (!visited[i])
			{
				DFS(i, visited, Stack);
			}
		}

		cout << "Topological Order (DFS-based): ";
		while (!Stack.empty())
		{
			cout << Stack.top() << " ";
			Stack.pop();
		}
		cout << endl;
	}
};

int main()
{
	Graph g(6);

	g.AddEdge(5, 2);
	g.AddEdge(5, 0);
	g.AddEdge(4, 0);
	g.AddEdge(4, 1);
	g.AddEdge(2, 3);
	g.AddEdge(3, 1);

	g.TopologicalSort();

	return 0;
}

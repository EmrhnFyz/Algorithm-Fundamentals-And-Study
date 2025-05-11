/*
	Problem: Topological Sort (DFS-based)

	Given a directed acyclic graph (DAG), return a topological ordering of its nodes.
	A topological order is a linear sequence where for every directed edge u -> v,
	node u comes before v in the order.

	----------------------------------------------------
	Idea:
	- Perform DFS for each unvisited node.
	- After visiting all descendants of a node, add it to a stack.
	- Once all nodes are processed, pop the stack to get the topological order.

	Learning Highlights:
	- Time Complexity: O(V + E)
	- Space Complexity: O(V)
	- Uses post-order DFS
	- Works only for DAGs (must check separately for cycles if needed)
	----------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph
{
	int nodeCount;
	vector<vector<int>> adjacencyList;

	// Helper DFS function to recursively visit nodes
	void DepthFirstSearch(int node, vector<bool>& visited, stack<int>& resultStack)
	{
		visited[node] = true; // Mark current node as visited

		// Explore all neighbors (outgoing edges) of this node
		for (int neighbor : adjacencyList[node])
		{
			if (!visited[neighbor])
			{
				DepthFirstSearch(neighbor, visited, resultStack);
			}
		}

		// After all neighbors are visited, push this node onto the stack.
		// This ensures that nodes with dependencies are pushed later and popped earlier.
		resultStack.push(node);
	}

public:
	Graph(int nodeCount)
	{
		this->nodeCount = nodeCount;
		adjacencyList.resize(nodeCount);
	}

	// Add a directed edge from 'from' to 'to'
	void AddEdge(int from, int to)
	{
		adjacencyList[from].push_back(to);
	}

	void PerformTopologicalSort()
	{
		vector<bool> visited(nodeCount, false); // Track visited nodes
		stack<int> resultStack; // Store the result in reverse order

		// Perform DFS from every unvisited node (handles disconnected components)
		for (int node = 0; node < nodeCount; ++node)
		{
			if (!visited[node])
			{
				DepthFirstSearch(node, visited, resultStack);
			}
		}

		// Pop all nodes from the stack to get the topological order
		cout << "Topological Order (DFS-based): ";
		while (!resultStack.empty())
		{
			cout << resultStack.top() << " ";
			resultStack.pop();
		}
		cout << endl;
	}
};

int main()
{
	/*
		DAG:
		5 -> 2
		5 -> 0
		4 -> 0
		4 -> 1
		2 -> 3
		3 -> 1

		One valid topological order: 5 4 2 3 1 0
	*/

	Graph graph(6);
	graph.AddEdge(5, 2);
	graph.AddEdge(5, 0);
	graph.AddEdge(4, 0);
	graph.AddEdge(4, 1);
	graph.AddEdge(2, 3);
	graph.AddEdge(3, 1);

	graph.PerformTopologicalSort();

	return 0;
}

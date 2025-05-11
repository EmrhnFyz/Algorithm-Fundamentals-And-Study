/*
	Problem: All-Pairs Shortest Path (Floyd-Warshall Algorithm)

	Given a weighted directed graph, find the shortest distance between every
	pair of nodes. Works with negative weights but not with negative cycles.

	----------------------------------------------------
	Idea:
	- Initialize distance matrix with edge weights.
	- Distance from node to itself is 0.
	- Try every node k as an intermediate step:
		For each pair (i, j):
			if dist[i][k] + dist[k][j] < dist[i][j],
			update dist[i][j] = dist[i][k] + dist[k][j]

	Learning Highlights:
	- Time Complexity: O(V³)
	- Space Complexity: O(V²)
	- Supports negative weights
	- Detects negative cycles (diagonal check: dist[i][i] < 0)
	----------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <__msvc_ostream.hpp>
#include <utility>

using namespace std;

const int INF = 1e9; // Use large value as "infinity"

void FloydWarshall(int nodeCount, vector<vector<int>>& distanceMatrix)
{
	// Try every node as an intermediate
	for (int intermediate = 0; intermediate < nodeCount; ++intermediate)
	{
		for (int from = 0; from < nodeCount; ++from)
		{
			for (int to = 0; to < nodeCount; ++to)
			{
				if (distanceMatrix[from][intermediate] < INF && distanceMatrix[intermediate][to] < INF)
				{
					distanceMatrix[from][to] = min(distanceMatrix[from][to], distanceMatrix[from][intermediate] + distanceMatrix[intermediate][to]);
				}
			}
		}
	}
}

void PrintDistanceMatrix(const vector<vector<int>>& matrix)
{
	int size = matrix.size();
	for (int from = 0; from < size; ++from)
	{
		for (int to = 0; to < size; ++to)
		{
			if (matrix[from][to] == INF)
				cout << setw(6) << "INF";
			else
				cout << setw(6) << matrix[from][to];
		}
		cout << endl;
	}
}


void RunTestCase(bool withNegativeCycle)
{
	int nodeCount = 4;
	vector<vector<int>> dist(nodeCount, vector<int>(nodeCount, INF));

	// Distance from node to itself is 0
	for (int i = 0; i < nodeCount; ++i)
		dist[i][i] = 0;

	// Edges
	dist[0][1] = 3;
	dist[0][2] = 6;
	dist[1][2] = 4;
	dist[1][3] = 4;
	dist[2][3] = 8;

	if (withNegativeCycle)
	{
		dist[3][0] = -10; // Creates a negative-weight cycle
	}
	else
	{
		dist[3][0] = 5; // Safe case (no negative cycle)
	}

	// Run Floyd-Warshall
	FloydWarshall(nodeCount, dist);

	if (withNegativeCycle)
	{
		cout << "\n--- With Negative-Weight Cycle ---\n";
	}
	else
	{
		cout << "--- No Negative Cycle ---\n";
	}

	// Check for negative cycle
	bool hasNegativeCycle = false;
	for (int i = 0; i < nodeCount; ++i)
	{
		if (dist[i][i] < 0)
		{
			hasNegativeCycle = true;
			break;
		}
	}

	if (hasNegativeCycle)
	{
		cout << "Negative-weight cycle detected! Shortest paths not valid.\n";
	}
	else
	{
		cout << "All-pairs shortest distances:\n";
		PrintDistanceMatrix(dist);
	}
}

int main()
{
	// Safe graph (no negative cycle)
	RunTestCase(false);

	// Unsafe graph (introduces negative-weight cycle)
	RunTestCase(true);

	return 0;
}

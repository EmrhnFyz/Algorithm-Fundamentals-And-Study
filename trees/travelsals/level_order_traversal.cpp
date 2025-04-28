/*
	Problem: Level-Order Traversal of a Binary Tree

	Traverse the binary tree **level by level** from top to bottom, left to right.

	Example:
	Given the binary tree:
		   1
		  / \
		 2   3
		/ \   \
	   4   5   6

	Level order traversal: [1, 2, 3, 4, 5, 6]

	----------------------------------------------------
	Idea:
	- Use a queue to process nodes level-by-level (Breadth-First Search style).
	- Steps:
		1. Start by pushing the root into the queue.
		2. While queue is not empty:
			- Pop front node.
			- Process the node.
			- Push left child (if exists) into queue.
			- Push right child (if exists) into queue.

	Learning Highlights:
	- Time Complexity: O(n) — visit each node exactly once.
	- Space Complexity: O(n) — storing nodes in queue (worst case all nodes at one level).
	- Essential for problems like:
		- Finding shortest path in unweighted graphs
		- Finding level of nodes
		- Grouping nodes by depth

	----------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x) : val(x), left(nullptr), right(nullptr)
	{}
};

// Main function to perform level-order traversal
vector<int> LevelOrderTraversal(TreeNode* root)
{
	vector<int> result;
	if (!root)
	{
		return result; // Handle empty tree
	}

	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty())
	{
		TreeNode* current = q.front();
		q.pop();

		result.push_back(current->val); // Visit the node

		if (current->left)
		{
			q.push(current->left); // Push left child
		}
		if (current->right)
		{
			q.push(current->right); // Push right child
		}
	}

	return result;
}

// Utility function to build a simple tree for testing
TreeNode* BuildExampleTree()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->right = new TreeNode(6);
	return root;
}

int main()
{
	TreeNode* root = BuildExampleTree();

	vector<int> result = LevelOrderTraversal(root);

	cout << "Level Order Traversal: ";
	for (int val : result)
	{
		cout << val << " ";
	}

	cout << endl;

	return 0;
}

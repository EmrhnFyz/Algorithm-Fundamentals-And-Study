/*
	Problem: Level Order Traversal (Breadth-First Search)

	Given a binary tree, print or return the values of nodes
	level by level (top to bottom, left to right).

	Example:
		   1
		  / \
		 2   3
		/ \
	   4   5

	Level order: [1, 2, 3, 4, 5]

	----------------------------------------------------
	Idea:
	- Use a queue to perform breadth-first traversal.
	- Enqueue the root, then for each node:
		- Process its value
		- Enqueue its left and right children (if any)

	Learning Highlights:
	- Time Complexity: O(n) — visit each node once
	- Space Complexity: O(n) — queue can hold one full level of the tree
	----------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <queue>
#include <__msvc_ostream.hpp>
using namespace std;

// Binary tree node definition
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int value) : val(value), left(nullptr), right(nullptr)
	{}
};

// Iterative BFS using a queue
void LevelOrder(TreeNode* root, vector<int>& result)
{
	if (root == nullptr)
	{
		return;
	}

	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty())
	{
		TreeNode* curr = q.front();
		q.pop();

		result.push_back(curr->val);  // Visit the node

		if (curr->left)
		{
			q.push(curr->left);   // Enqueue left child
		}
		if (curr->right)
		{
			q.push(curr->right); // Enqueue right child
		}
	}
}

// Sample tree (same as previous)
TreeNode* BuildSampleTree()
{
	// Tree structure:
	//        1
	//       / \
    //      2   3
	//     / \
    //    4   5

	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	return root;
}

int main()
{
	TreeNode* root = BuildSampleTree();

	vector<int> result;
	LevelOrder(root, result);

	cout << "Level-order traversal: ";
	for (int val : result)
	{
		cout << val << " ";
	}

	cout << endl;

	return 0;
}

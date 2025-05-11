/*
	Problem: Diameter of a Binary Tree

	The diameter of a binary tree is the length (in edges) of the longest path
	between any two nodes. This path **may or may not pass through the root**.

	----------------------------------------------------
	Idea:
	- At each node, the longest path "through" that node is:
		height(left subtree) + height(right subtree) + 2
	- Use post-order traversal to compute height while updating diameter.

	Learning Highlights:
	- Time Complexity: O(n) — each node visited once
	- Space Complexity: O(h) — recursion stack
	----------------------------------------------------
*/

#include <__msvc_ostream.hpp>
#include <iostream>
#include <utility>
using namespace std;

// Tree node definition
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int value) : val(value), left(nullptr), right(nullptr)
	{}
};

int maxDiameter = 0;

// Recursive function to compute height AND update diameter
int GetHeight(TreeNode* root)
{
	if (!root)
	{
		return -1;
	}

	int leftHeight = GetHeight(root->left);
	int rightHeight = GetHeight(root->right);

	int diameterThroughRoot = leftHeight + rightHeight + 2;
	maxDiameter = max(maxDiameter, diameterThroughRoot);

	return 1 + max(leftHeight, rightHeight);
}

int ComputeDiameter(TreeNode* root)
{
	maxDiameter = 0;         // reset global before traversal
	GetHeight(root);

	return maxDiameter;
}

// Sample tree builder
TreeNode* BuildSampleTree()
{
	/*
		   1
		  / \
		 2   3
		/     \
	   4       5
				\
				 6

	Longest path: 4 -> 2 -> 1 -> 3 -> 5 -> 6 (5 edges)
	*/
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->right->right = new TreeNode(5);
	root->right->right->right = new TreeNode(6);
	return root;
}

int main()
{
	TreeNode* root = BuildSampleTree();

	int diameter = ComputeDiameter(root);
	cout << "Diameter of the tree: " << diameter << endl;

	return 0;
}

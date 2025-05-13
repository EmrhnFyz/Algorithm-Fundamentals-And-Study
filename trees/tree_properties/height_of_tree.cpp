/*
	Problem: Height of a Binary Tree

	Given a binary tree, return the height of the tree.

	----------------------------------------------------
	Idea:
	- The height of a tree is the number of edges on the longest path
	  from the root to any leaf node.
	- If a node is null, its height is -1 (no edges).
	- If a node is a leaf, its height is 0.

	We compute height recursively as:
		height = 1 + max(height(left), height(right))

	Learning Highlights:
	- Time Complexity: O(n) — visit each node once
	- Space Complexity: O(h) — due to recursion (h = height of tree)
	----------------------------------------------------
*/

#include <iostream>
#include <utility>
#include <__msvc_ostream.hpp>
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

// Recursive function to compute height
int TreeHeight(TreeNode* root)
{
	if (!root)
	{
		return -1; // base case: height of null node is -1 (0 edges)
	}

	int leftHeight = TreeHeight(root->left);
	int rightHeight = TreeHeight(root->right);

	return 1 + max(leftHeight, rightHeight);
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

	Height = 2 (path: 1 -> 3 -> 5 or 1 -> 2 -> 4)
	*/
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->right->right = new TreeNode(5);
	return root;
}

int main()
{
	TreeNode* root = BuildSampleTree();

	int height = TreeHeight(root);
	cout << "Height of the tree: " << height << endl;

	return 0;
}

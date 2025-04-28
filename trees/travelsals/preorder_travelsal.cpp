/*
	Problem: Preorder Traversal of a Binary Tree

	Traverse the binary tree in preorder:
	- Visit the root node first
	- Then recursively visit the left subtree
	- Then recursively visit the right subtree

	Example:
	Given the binary tree:
		   1
			\
			 2
			/
		   3

	Preorder traversal: [1, 2, 3]

	----------------------------------------------------
	Idea:
	- Preorder = "root first, then left, then right."
	- Use recursion:
		- Process current node.
		- Recursively traverse the left subtree.
		- Recursively traverse the right subtree.

	Learning Highlights:
	- Time Complexity: O(n) — visit each node exactly once.
	- Space Complexity: O(h) — height of tree due to recursion stack (O(n) worst case if tree is skewed).
	- Fundamental technique for many tree-related algorithms.

	----------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <__msvc_ostream.hpp>
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

// Helper function to perform preorder traversal
void Preorder(TreeNode* node, vector<int>& result)
{
	if (!node)
	{
		return; // Base case: if node is null, do nothing
	}

	result.push_back(node->val);    // Visit the root node
	Preorder(node->left, result);   // Traverse left subtree
	Preorder(node->right, result);  // Traverse right subtree
}

// Main function to call traversal
vector<int> PreorderTraversal(TreeNode* root)
{
	vector<int> result;
	Preorder(root, result);
	return result;
}

// Utility function to build a simple tree for testing
TreeNode* BuildExampleTree()
{
	TreeNode* root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);
	return root;
}

int main()
{
	TreeNode* root = BuildExampleTree();

	vector<int> result = PreorderTraversal(root);

	cout << "Preorder Traversal: ";
	for (int val : result) cout << val << " ";
	cout << endl;

	return 0;
}

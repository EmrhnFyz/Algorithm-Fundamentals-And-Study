/*
	Problem: Inorder Traversal of a Binary Tree

	Traverse the binary tree in inorder:
	- Visit the left subtree first
	- Then visit the root node
	- Then visit the right subtree

	Example:
	Given the binary tree:
		   1
			\
			 2
			/
		   3

	Inorder traversal: [1, 3, 2]

	----------------------------------------------------
	Idea:
	- Inorder = "left first, then root, then right."
	- Use recursion:
		- Recursively traverse the left subtree.
		- Process the current node.
		- Recursively traverse the right subtree.

	Learning Highlights:
	- Time Complexity: O(n) — visit each node exactly once.
	- Space Complexity: O(h) — height of tree due to recursion stack (O(n) worst case if tree is skewed).
	- Inorder traversal of a **Binary Search Tree (BST)** gives **sorted order**!

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

// Helper function to perform inorder traversal
void Inorder(TreeNode* node, vector<int>& result)
{
	if (!node)
	{
		return; // Base case: if node is null, do nothing
	}

	Inorder(node->left, result);   // Traverse left subtree
	result.push_back(node->val);   // Visit the root node
	Inorder(node->right, result);  // Traverse right subtree
}

// Main function to call traversal
vector<int> InorderTraversal(TreeNode* root)
{
	vector<int> result;
	Inorder(root, result);
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

	vector<int> result = InorderTraversal(root);

	cout << "Inorder Traversal: ";
	for (int val : result)
	{
		cout << val << " ";
	}
	cout << endl;

	return 0;
}

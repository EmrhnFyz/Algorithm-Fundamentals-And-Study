/*
	Problem: Inorder Traversal of a Binary Tree

	Given a binary tree, print or return the values of the nodes
	in inorder traversal order: Left → Root → Right

	Example:
		   1
		  / \
		 2   3
		/ \
	   4   5

	Inorder: [4, 2, 5, 1, 3]

	----------------------------------------------------
	Idea:
	- In inorder traversal, we recursively visit the left subtree,
	  then process the current node, then the right subtree.
	- In binary search trees (BSTs), inorder traversal gives sorted order.

	Learning Highlights:
	- Time Complexity: O(n) — visit each node once
	- Space Complexity: O(h) — due to recursion (h = height of the tree)
	----------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <__msvc_ostream.hpp>
using namespace std;

// Binary tree node definition (same as before)
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int value) : val(value), left(nullptr), right(nullptr)
	{}
};

// Recursive inorder traversal
void Inorder(TreeNode* root, vector<int>& result)
{
	if (root == nullptr)
	{
		return;
	}

	Inorder(root->left, result);    // Traverse left subtree
	result.push_back(root->val);    // Visit the root
	Inorder(root->right, result);   // Traverse right subtree
}

// Sample tree (same structure as preorder)
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
	Inorder(root, result);

	cout << "Inorder traversal: ";
	for (int val : result)
	{
		cout << val << " ";
	}

	cout << endl;

	return 0;
}

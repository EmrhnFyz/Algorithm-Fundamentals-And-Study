/*
	Problem: Preorder Traversal of a Binary Tree

	Given a binary tree, print or return the values of the nodes
	in preorder traversal order: Root → Left → Right

	Example:
		   1
		  / \
		 2   3
		/ \
	   4   5

	Preorder: [1, 2, 4, 5, 3]

	----------------------------------------------------
	Idea:
	- In preorder traversal, we visit the current node first,
	  then recursively traverse the left subtree, then the right subtree.
	- This is often used when:
		- You want to copy a tree
		- You want to evaluate prefix expressions (in expression trees)

	Learning Highlights:
	- Time Complexity: O(n) — every node is visited once
	- Space Complexity: O(h) — recursion stack (h = tree height)
	----------------------------------------------------
*/

#include <iostream>
#include <vector>
using namespace std;

// Definition of a binary tree node
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int value) : val(value), left(nullptr), right(nullptr)
	{}
};

// Recursive preorder traversal function
void Preorder(TreeNode* root, vector<int>& result)
{
	if (root == nullptr)
	{
		return;
	}

	result.push_back(root->val);     // Visit the root
	Preorder(root->left, result);    // Traverse left subtree
	Preorder(root->right, result);   // Traverse right subtree
}

// Utility function to build a sample tree
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
	Preorder(root, result);

	cout << "Preorder traversal: ";
	for (int val : result)
	{
		cout << val << " ";
	}

	cout << endl;

	return 0;
}

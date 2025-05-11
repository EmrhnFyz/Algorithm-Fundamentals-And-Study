/*
	Problem: Postorder Traversal of a Binary Tree

	Given a binary tree, print or return the values of the nodes
	in postorder traversal order: Left -> Right -> Root

	Example:
		   1
		  / \
		 2   3
		/ \
	   4   5

	Postorder: [4, 5, 2, 3, 1]

	----------------------------------------------------
	Idea:
	- In postorder traversal, we recursively visit the left subtree,
	  then the right subtree, and finally process the current node.
	- This is commonly used for:
		- Deleting/freeing trees
		- Evaluating postfix expressions
		- Bottom-up aggregations (like path sums, height, etc.)

	Learning Highlights:
	- Time Complexity: O(n) — each node visited once
	- Space Complexity: O(h) — recursion stack depth (tree height)
	----------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <__msvc_ostream.hpp>
using namespace std;

// Binary tree node structure
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int value) : val(value), left(nullptr), right(nullptr)
	{}
};

// Recursive postorder traversal
void Postorder(TreeNode* root, vector<int>& result)
{
	if (root == nullptr)
	{
		return;
	}

	Postorder(root->left, result);   // Traverse left subtree
	Postorder(root->right, result);  // Traverse right subtree
	result.push_back(root->val);     // Visit the root last
}

// Reuse same tree as previous
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
	Postorder(root, result);

	cout << "Postorder traversal: ";

	for (int val : result)
	{
		cout << val << " ";
	}

	cout << endl;

	return 0;
}

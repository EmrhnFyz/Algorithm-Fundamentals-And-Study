/*
	Problem: Insert into a Binary Search Tree

	Given a value, insert it into the correct position in a BST
	so that the tree remains a valid Binary Search Tree.

	----------------------------------------------------
	Idea:
	- Traverse down the tree:
		- If value < current -> go left
		- If value > current -> go right
	- When you reach a null position, insert the new node there.
	- Duplicate values are typically not inserted in a classic BST.

	Learning Highlights:
	- Time Complexity: O(h) where h = height of the tree
		-> O(log n) for balanced, O(n) for skewed
	- Space Complexity: O(h) recursive stack
	----------------------------------------------------
*/

#include <iostream>
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

// Recursive insert function
TreeNode* InsertBST(TreeNode* root, int value)
{
	if (root == nullptr)
	{
		return new TreeNode(value); // Found correct spot to insert
	}

	if (value < root->val)
	{
		root->left = InsertBST(root->left, value);  // Insert in left subtree
	}
	else if (value > root->val)
	{
		root->right = InsertBST(root->right, value); // Insert in right subtree
	}
	// Do nothing for duplicates

	return root; // Return unchanged root pointer
}

// Sample BST builder
TreeNode* buildSampleBST()
{
	/*
			 6
			/ \
		   3   8
		  / \    \
		 2   5    9
	*/
	TreeNode* root = new TreeNode(6);
	root->left = new TreeNode(3);
	root->right = new TreeNode(8);
	root->left->left = new TreeNode(2);
	root->left->right = new TreeNode(5);
	root->right->right = new TreeNode(9);
	return root;
}

// Inorder traversal to verify BST structure
void Inorder(TreeNode* root)
{
	if (!root) return;
	Inorder(root->left);
	cout << root->val << " ";
	Inorder(root->right);
}

int main()
{
	TreeNode* root = buildSampleBST();

	int valueToInsert = 7;
	root = InsertBST(root, valueToInsert);

	cout << "Inorder after insertion: ";
	Inorder(root); // Should now include 7 in correct position
	cout << endl;

	return 0;
}

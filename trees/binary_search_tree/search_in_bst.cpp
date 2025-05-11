/*
	Problem: Search in a Binary Search Tree

	Given a binary search tree (BST) and a target value,
	return the node that contains the target value.
	If the value doesn't exist, return nullptr.

	----------------------------------------------------
	Idea:
	- BST property: For every node,
		Left child < Current node < Right child
	- Start at root:
		- If target < current, go left
		- If target > current, go right
		- If target == current, return current

	Learning Highlights:
	- Time Complexity: O(h), where h = height of the tree
		-> O(log n) for balanced trees, O(n) for skewed ones
	- Space Complexity: O(h) recursive stack (or O(1) if iterative)
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

// Recursive search
TreeNode* searchBST(TreeNode* root, int target)
{
	if (root == nullptr)
	{
		return nullptr;         // Reached leaf, not found
	}
	if (root->val == target)
	{
		return root;        // Match found
	}

	if (target < root->val)
	{
		return searchBST(root->left, target);    // Go left
	}
	else
	{
		return searchBST(root->right, target);   // Go right
	}
}

// Sample binary search tree
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

int main()
{
	TreeNode* root = buildSampleBST();

	int target = 5;
	TreeNode* found = searchBST(root, target);

	if (found)
	{
		cout << "Target " << target << " found at node with value: " << found->val << endl;
	}
	else
	{
		cout << "Target " << target << " not found in the tree." << endl;
	}

	return 0;
}

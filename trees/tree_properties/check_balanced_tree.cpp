/*
	Problem: Check if a Binary Tree is Height-Balanced

	A binary tree is height-balanced if, for every node:
		|height(left) - height(right)| ≤ 1

	----------------------------------------------------
	Idea:
	- Use post-order traversal to check balance from bottom-up.
	- At each node, compute height AND check balance of subtrees.
	- Return -1 immediately if any subtree is unbalanced.

	Learning Highlights:
	- Time Complexity: O(n)
	- Space Complexity: O(h) recursion stack
	----------------------------------------------------
*/

#include <iostream>
#include <algorithm>
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

// Helper function to check height and balance
int CheckBalance(TreeNode* root)
{
	if (!root)
	{
		return 0;
	}

	int left = CheckBalance(root->left);
	if (left == -1)
	{
		return -1;
	}

	int right = CheckBalance(root->right);
	if (right == -1)
	{
		return -1;
	}

	if (abs(left - right) > 1)
	{
		return -1;
	}

	return 1 + max(left, right);
}

bool IsBalanced(TreeNode* root)
{
	return CheckBalance(root) != -1;
}

// Sample tree builders
TreeNode* BuildBalancedTree()
{
	/*
		   1
		  / \
		 2   3
		/
	   4
	*/
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	return root;
}

TreeNode* BuildUnbalancedTree()
{
	/*
		   1
		  /
		 2
		/
	   3
	*/
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(3);
	return root;
}

int main()
{
	TreeNode* balanced = BuildBalancedTree();
	TreeNode* unbalanced = BuildUnbalancedTree();

	cout << "Is balanced tree balanced? " << (IsBalanced(balanced) ? "Yes" : "No") << endl;
	cout << "Is unbalanced tree balanced? " << (IsBalanced(unbalanced) ? "Yes" : "No") << endl;

	return 0;
}

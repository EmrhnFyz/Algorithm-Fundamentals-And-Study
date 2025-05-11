/*
	Problem: Lowest Common Ancestor (LCA) of Two Nodes in a Binary Tree

	Given a binary tree and two node values `p` and `q`, return the lowest (deepest) node
	that is an ancestor of both nodes. A node can be an ancestor of itself.

	----------------------------------------------------
	Idea:
	- Use post-order traversal:
		- If current node is null -> return null
		- If current node is p or q -> return current
		- Recursively search left and right subtrees
		- If both sides return non-null -> this node is LCA
		- If only one side returns non-null -> propagate it upward

	Learning Highlights:
	- Time Complexity: O(n) — visit every node once
	- Space Complexity: O(h) — recursion stack
	----------------------------------------------------
*/

#include <iostream>
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

// Recursive LCA function
TreeNode* LowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	if (!root || root == p || root == q)
	{
		return root;
	}

	TreeNode* left = LowestCommonAncestor(root->left, p, q);
	TreeNode* right = LowestCommonAncestor(root->right, p, q);

	if (left && right)
	{
		return root;         // Both sides returned non-null -> current is LCA
	}

	return left ? left : right;            // Only one side has an answer
}

// Sample tree builder
TreeNode* BuildSampleTree(TreeNode*& p, TreeNode*& q)
{
	/*
		   3
		  / \
		 5   1
		/ \ / \
	   6  2 0  8
		 / \
		7   4

	LCA of 7 and 4 is 2
	LCA of 6 and 4 is 5
	LCA of 6 and 8 is 3
	*/
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(5);
	root->right = new TreeNode(1);
	root->left->left = new TreeNode(6);
	root->left->right = new TreeNode(2);
	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(8);
	root->left->right->left = new TreeNode(7);
	root->left->right->right = new TreeNode(4);

	// Set reference pointers to 7 and 4
	p = root->left->right->left;   // Node 7
	q = root->left->right->right;  // Node 4

	return root;
}

int main()
{
	TreeNode* p;
	TreeNode* q;
	TreeNode* root = BuildSampleTree(p, q);

	TreeNode* lca = LowestCommonAncestor(root, p, q);

	cout << "LCA of " << p->val << " and " << q->val << " is: " << lca->val << endl;

	return 0;
}

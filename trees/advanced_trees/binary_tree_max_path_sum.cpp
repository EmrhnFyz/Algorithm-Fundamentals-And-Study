/*
	Problem: Binary Tree Maximum Path Sum

	A **path** in a binary tree is any sequence of nodes from some starting node to any node
	in the tree along the parent-child connections. The path must contain **at least one node**
	and does **not need to pass through the root**.

	Return the **maximum path sum** of any such path.

	----------------------------------------------------
	Idea:
	- Use post-order traversal.
	- At each node:
		- Compute max gain from left and right subtrees.
		- Update global max path sum using:
			left_gain + node.val + right_gain
		- Return max path *to propagate upward*: node.val + max(left, right)

	- If gain from left/right is negative, treat it as 0 (ignore that side).

	Learning Highlights:
	- Time Complexity: O(n)
	- Space Complexity: O(h) recursion stack
	----------------------------------------------------
*/

#include <iostream>
#include <algorithm>
#include <climits>
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

int maxSum = INT_MIN;

// Recursive post-order traversal to compute max path
int MaxGain(TreeNode* root)
{
	if (!root)
	{
		return 0;
	}

	// Recursively get max gain from left and right subtrees
	int leftGain = max(0, MaxGain(root->left));   // discard negative gains
	int rightGain = max(0, MaxGain(root->right));

	// Update global max with current path through this node
	int priceNewPath = root->val + leftGain + rightGain;
	maxSum = max(maxSum, priceNewPath);

	// Return the max path that can be extended to parent
	return root->val + max(leftGain, rightGain);
}

int MaxPathSum(TreeNode* root)
{
	maxSum = INT_MIN; // reset global
	MaxGain(root);
	return maxSum;
}

// Sample tree
TreeNode* buildSampleTree()
{
	/*
		   -10
		   /  \
		  9   20
			  / \
			 15  7

	Max path: 15 -> 20 -> 7 = 42
	*/
	TreeNode* root = new TreeNode(-10);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	return root;
}

int main()
{
	TreeNode* root = buildSampleTree();

	int result = MaxPathSum(root);
	cout << "Maximum path sum: " << result << endl;

	return 0;
}

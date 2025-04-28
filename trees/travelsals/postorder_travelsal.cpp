/*
	Problem: Postorder Traversal of a Binary Tree

	Traverse the binary tree in postorder:
	- Visit the left subtree first
	- Then visit the right subtree
	- Then visit the root node last

	Example:
	Given the binary tree:
		   1
			\
			 2
			/
		   3

	Postorder traversal: [3, 2, 1]

	----------------------------------------------------
	Idea:
	- Postorder = "left first, then right, then root."
	- Use recursion:
		- Recursively traverse the left subtree.
		- Recursively traverse the right subtree.
		- Process the current node.

	Learning Highlights:
	- Time Complexity: O(n) — visit each node exactly once.
	- Space Complexity: O(h) — height of tree due to recursion stack (O(n) worst case if tree is skewed).
	- Postorder is especially useful for problems like:
		- Deleting entire trees
		- Calculating subtree properties (sum, size)
		- Complex evaluations (expression trees)

	----------------------------------------------------
*/

#include <iostream>
#include <vector>
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

// Helper function to perform postorder traversal
void Postorder(TreeNode* node, vector<int>& result)
{
	if (!node)
	{
		return; // Base case: if node is null, do nothing
	}

	Postorder(node->left, result);   // Traverse left subtree
	Postorder(node->right, result);  // Traverse right subtree
	result.push_back(node->val);     // Visit the root node
}

// Main function to call traversal
vector<int> PostorderTraversal(TreeNode* root)
{
	vector<int> result;
	Postorder(root, result);
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

	vector<int> result = PostorderTraversal(root);

	cout << "Postorder Traversal: ";
	for (int val : result)
	{
		cout << val << " ";
	}
	cout << endl;

	return 0;
}

/*
	Problem: Delete a Node from a Binary Search Tree

	Given the root of a BST and a value to delete,
	remove the node and return the new root of the tree.

	----------------------------------------------------
	Idea:
	- Use recursion to locate the node.
	- Once found, handle 3 cases:
		1. Node has **no children** -> return nullptr.
		2. Node has **one child** -> return the child.
		3. Node has **two children**:
			- Find the **inorder successor** (smallest in right subtree),
			- Copy its value into the current node,
			- Recursively delete the successor.

	Learning Highlights:
	- Time Complexity: O(h) — h = height of tree
	- Space Complexity: O(h) recursive stack
	----------------------------------------------------
*/

#include <iostream>
#include <__msvc_ostream.hpp>
using namespace std;

// TreeNode structure
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int value) : val(value), left(nullptr), right(nullptr)
	{}
};

// Helper: find min value in a subtree (used for 2-child deletion)
TreeNode* FindMin(TreeNode* root)
{
	while (root && root->left)
	{
		root = root->left;
	}
	return root;
}

// Recursive delete function
TreeNode* DeleteBST(TreeNode* root, int key)
{
	if (root == nullptr) return nullptr;

	if (key < root->val)
	{
		root->left = DeleteBST(root->left, key); // Go left
	}
	else if (key > root->val)
	{
		root->right = DeleteBST(root->right, key); // Go right
	}
	else
	{
		// Found the node to delete
		if (!root->left && !root->right)
		{
			delete root;            // Case 1: leaf node
			return nullptr;
		}
		else if (!root->left)
		{
			TreeNode* rightChild = root->right; // Case 2: only right child
			delete root;
			return rightChild;
		}
		else if (!root->right)
		{
			TreeNode* leftChild = root->left;   // Case 2: only left child
			delete root;
			return leftChild;
		}
		else
		{
			// Case 3: two children
			TreeNode* successor = FindMin(root->right); // smallest in right subtree
			root->val = successor->val;                 // copy value
			root->right = DeleteBST(root->right, successor->val); // delete duplicate
		}
	}

	return root;
}

// Inorder to verify structure
void Inorder(TreeNode* root)
{
	if (!root) return;
	Inorder(root->left);
	cout << root->val << " ";
	Inorder(root->right);
}

// Reuse previous BST
TreeNode* BuildSampleBST()
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
	TreeNode* root = BuildSampleBST();

	cout << "Inorder before deletion: ";
	Inorder(root);
	cout << endl;

	int valueToDelete = 3;
	root = DeleteBST(root, valueToDelete);

	cout << "Inorder after deleting " << valueToDelete << ": ";
	Inorder(root);
	cout << endl;

	return 0;
}

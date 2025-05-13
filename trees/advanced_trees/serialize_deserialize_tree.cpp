/*
	Problem: Serialize and Deserialize a Binary Tree

	- Serialization converts a tree into a string (or sequence).
	- Deserialization rebuilds the same tree from that string.

	----------------------------------------------------
	Idea:
	- Use **preorder traversal** with null markers ("#") for empty nodes.
	- Example serialization: "1,2,#,#,3,4,#,#,5,#,#"
	- During deserialization, read values one by one and recursively rebuild the tree.

	Learning Highlights:
	- Time Complexity:
		- Serialize: O(n)
		- Deserialize: O(n)
	- Space Complexity: O(h) for recursion (h = tree height)
	----------------------------------------------------
*/

#include <iostream>
#include <sstream>
#include <iosfwd>
#include <string>
#include <__msvc_ostream.hpp>
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

// Serialize tree to string using preorder traversal
void SerializeHelper(TreeNode* root, ostringstream& out)
{
	if (!root)
	{
		out << "# ";
		return;
	}
	out << root->val << " ";
	SerializeHelper(root->left, out);
	SerializeHelper(root->right, out);
}

string Serialize(TreeNode* root)
{
	ostringstream out;
	SerializeHelper(root, out);
	return out.str();
}

// Deserialize from string into tree using preorder structure
TreeNode* DeserializeHelper(istringstream& in)
{
	string val;
	in >> val;

	if (val == "#")
	{
		return nullptr;
	}

	TreeNode* node = new TreeNode(stoi(val));
	node->left = DeserializeHelper(in);
	node->right = DeserializeHelper(in);
	return node;
}

TreeNode* Deserialize(const string& data)
{
	istringstream in(data);
	return DeserializeHelper(in);
}

// Inorder print for visual verification
void Inorder(TreeNode* root)
{
	if (!root)
	{
		return;
	}
	Inorder(root->left);
	cout << root->val << " ";
	Inorder(root->right);
}

// Sample tree builder
TreeNode* BuildSampleTree()
{
	/*
		   1
		  / \
		 2   3
		/ \
	       4   5
	*/
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(5);
	return root;
}

int main()
{
	TreeNode* root = BuildSampleTree();

	string serialized = Serialize(root);
	cout << "Serialized: " << serialized << endl;

	TreeNode* newRoot = Deserialize(serialized);

	cout << "Inorder of deserialized tree: ";
	Inorder(newRoot);
	cout << endl;

	return 0;
}

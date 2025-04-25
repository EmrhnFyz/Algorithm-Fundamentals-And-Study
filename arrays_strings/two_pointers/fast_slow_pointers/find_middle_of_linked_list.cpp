/*
	Problem: Find Middle of Linked List

	Given the head of a singly linked list, return the middle node.
	If there are two middle nodes, return the second one.

	Example:
	Input: 1 -> 2 -> 3 -> 4 -> 5
	Output: 3

	Input: 1 -> 2 -> 3 -> 4 -> 5 -> 6
	Output: 4

	----------------------------------------------------
	Learning Highlights:
	- Use slow and fast pointers.
	- Move slow by 1 step, fast by 2 steps.
	- When fast reaches the end, slow will be at the middle.
	- Time Complexity: O(n), Space Complexity: O(1)
	----------------------------------------------------
*/

#include <iostream>
#include <initializer_list>
#include <__msvc_ostream.hpp>
using namespace std;


// Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int v) : val(v), next(nullptr)
	{}
};

#pragma region Solution
ListNode* FindMiddle(ListNode* head)
{
	ListNode* slow = head;
	ListNode* fast = head;

	// Traverse the list with two pointers
	// fast moves 2 steps at a time, slow moves 1 step
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	// When fast reaches the end (or null), slow will be at the middle
	return slow;
}
#pragma endregion

#pragma region Utilities
// Helper to build a list from array values
ListNode* buildList(const initializer_list<int>& vals)
{
	ListNode dummy(0);
	ListNode* tail = &dummy;
	for (int v : vals)
	{
		tail->next = new ListNode(v);
		tail = tail->next;
	}
	return dummy.next;
}

// Helper to print a list from a given node
void PrintList(ListNode* head)
{
	while (head)
	{
		cout << head->val;
		if (head->next) cout << " -> ";
		head = head->next;
	}
	cout << endl;
}
#pragma endregion


int main()
{
	ListNode* head = buildList({ 1, 2, 3, 4, 5, 6 });
	cout << "Original list: ";
	PrintList(head);

	ListNode* mid = FindMiddle(head);
	cout << "Middle node: " << mid->val << endl; // Expected: 4

	ListNode* head2 = buildList({ 1, 2, 3, 4, 5 });
	cout << "Original list: ";
	PrintList(head2);

	ListNode* mid2 = FindMiddle(head2);
	cout << "Middle node: " << mid2->val << endl; // Expected: 3


	return 0;
}

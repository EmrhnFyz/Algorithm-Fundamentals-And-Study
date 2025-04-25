/*
	Problem: Find Start of Cycle in a Linked List

	Given the head of a linked list that contains a cycle, return the node where the cycle begins.
	If there is no cycle, return nullptr.

	Example:
	Input: head = [3,2,0,-4], pos = 1
	Output: Cycle starts at node with value: 2 at index: 1
	Explanation: There is a cycle in the linked list, where tail connects to the second node.

	Input: head = [1,2], pos = 0
	Output: Cycle starts at node with value: 1 at index: 0
	Explanation: There is a cycle in the linked list, where tail connects to the first node.

	Input: head = [1], pos = -1
	Output: No cycle detected.
	Explanation: There is no cycle in the linked list.

	----------------------------------------------------
	Learning Highlights:
	- First, detect the cycle using fast & slow pointers (Floyd’s algorithm).
	- When they meet, reset one pointer to head and move both one step at a time.
	- The point where they meet again is the start of the cycle.
	- Time Complexity: O(n), Space Complexity: O(1)
	----------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <__msvc_ostream.hpp>
#include <utility>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int v) : val(v), next(nullptr)
	{}
};

#pragma region Solution

pair<ListNode*, int> FindCycleStartWithIndex(ListNode* head)
{
	ListNode* slow = head;
	ListNode* fast = head;

	// Step 1: Detect if a cycle exists using fast & slow pointers
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;


		if (slow == fast)
		{
			// Cycle detected — now find the start of the cycle
			ListNode* entry = head;
			int index = 0;


			// Step 2: Move both pointers at same speed until they meet
			// One starts from head, other from meeting point
			while (entry != slow)
			{
				entry = entry->next;
				slow = slow->next;
				++index; // count how many steps from head
			}

			return { entry, index }; // cycle starts here
		}
	}

	return { nullptr, -1 }; // no cycle
}

#pragma endregion

#pragma region Utilities

ListNode* BuildListWithCycle(const vector<int>& vals, int cyclePos)
{
	ListNode dummy(0);
	ListNode* tail = &dummy;
	ListNode* cycleNode = nullptr;

	for (int i = 0; i < static_cast<int>(vals.size()); ++i)
	{
		tail->next = new ListNode(vals[i]);
		tail = tail->next;
		if (i == cyclePos)
		{
			cycleNode = tail;
		}
	}

	if (cyclePos != -1)
	{
		tail->next = cycleNode;
	}

	return dummy.next;
}

#pragma endregion

int main()
{
	vector<int> vals = { 3, 2, 0, -4 };
	int cyclePos = 1; // Create cycle starting at index 1 (value 2)
	ListNode* head = BuildListWithCycle(vals, cyclePos);

	pair<ListNode*, int> cycleStartData = FindCycleStartWithIndex(head);

	if (cycleStartData.first)
	{
		cout << "Cycle starts at node with value: " << cycleStartData.first->val << " at index: " << cycleStartData.second << endl;
	}
	else
	{
		cout << "No cycle detected." << endl;
	}

	vector<int> vals2 = { 1, 2 };
	cyclePos = 0; // Create cycle starting at index 0 (value 1)
	head = BuildListWithCycle(vals2, cyclePos);

	cycleStartData = FindCycleStartWithIndex(head);

	if (cycleStartData.first)
	{
		cout << "Cycle starts at node with value: " << cycleStartData.first->val << " at index: " << cycleStartData.second << endl;
	}
	else
	{
		cout << "No cycle detected." << endl;
	}

	vals2 = { 1 };
	cyclePos = -1; // No cycle
	head = BuildListWithCycle(vals2, cyclePos);
	cycleStartData = FindCycleStartWithIndex(head);

	if (cycleStartData.first)
	{
		cout << "Cycle starts at node with value: " << cycleStartData.first->val << " at index: " << cycleStartData.second << endl;
	}
	else
	{
		cout << "No cycle detected." << endl;
	}

	return 0;
}

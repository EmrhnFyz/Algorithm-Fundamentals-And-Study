/*
	Problem: Detect Cycle in a Linked List

	Given the head of a singly linked list, return true if there is a cycle in the linked list.
	Use constant memory (O(1) space).

	Example:
	Input: head = [3,2,0,-4], with a cycle connecting node 3 -> 2
	Output: true
	Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

	Input: head = [1,2], pos = 0
	Output: true
	Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

	Input: head = [1], pos = -1
	Output: false
	Explanation: There is no cycle in the linked list.


	----------------------------------------------------
	Learning Highlights:
	- Use two pointers (slow and fast).
	- If the list contains a cycle, fast will eventually meet slow.
	- Think of runners on a circular track: the faster one will lap the slower.
	- Time Complexity: O(n), Space Complexity: O(1)
	----------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <__msvc_ostream.hpp>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int v) : val(v), next(nullptr)
	{}
};

#pragma region Solution

bool HasCycle(ListNode* head)
{
	ListNode* slow = head;
	ListNode* fast = head;

	while (fast && fast->next)
	{
		slow = slow->next;             // Move by 1
		fast = fast->next->next;       // Move by 2

		if (slow == fast)
		{
			return true;               // Pointers meet: cycle exists
		}
	}

	return false;                      // Fast pointer reached end: no cycle
}

#pragma endregion

#pragma region Utilities
// Build a linked list and optionally create a cycle at `cyclePos`
// cyclePos: index to which the last node connects (-1 = no cycle)
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
		tail->next = cycleNode; // Create cycle
	}

	return dummy.next;
}

#pragma endregion

int main()
{
	// Test case with a cycle: 3 -> 2 -> 0 -> -4 -> (back to 2)
	vector<int> vals = { 3, 2, 0, -4 };
	int cyclePos = 1; // cycle starts at index 1 (value 2)
	ListNode* head = BuildListWithCycle(vals, cyclePos);

	cout << "Cycle detected? " << (HasCycle(head) ? "true" : "false") << endl;

	vector<int> vals2 = { 1, 2 };
	int cyclePos2 = 0; // cycle starts at index 0 (value 1)
	ListNode* head2 = BuildListWithCycle(vals2, cyclePos2);

	cout << "Cycle detected? " << (HasCycle(head2) ? "true" : "false") << endl;

	vector<int> vals3 = { 1 };
	int cyclePos3 = -1; // no cycle
	ListNode* head3 = BuildListWithCycle(vals3, cyclePos3);
	cout << "Cycle detected? " << (HasCycle(head3) ? "true" : "false") << endl;

	return 0;
}

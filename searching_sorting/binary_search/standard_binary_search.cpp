/*
	Problem: Standard Binary Search

	Given a sorted array of integers and a target value,
	return the index of the target if it exists, otherwise return -1.

	Example 1:

	Input: nums = [-1,0,3,5,9,12], target = 9
	Output: 4
	Explanation: 9 exists in nums and its index is 4
	Example 2:

	Input: nums = [-1,0,3,5,9,12], target = 2
	Output: -1
	Explanation: 2 does not exist in nums so return -1

	----------------------------------------------------
	Idea:
	- Use two pointers (`left` and `right`) to represent the current search range.
	- Find the middle index `mid`.
	- Compare nums[mid] with the target:
		- If equal -> target found at mid.
		- If nums[mid] < target -> search right half (left = mid + 1).
		- If nums[mid] > target -> search left half (right = mid - 1).
	- If left crosses right, the target does not exist.

	Learning Highlights:
	- Time Complexity: O(log n)
	- Space Complexity: O(1)
	- Divide-and-conquer idea: shrink search space by half each iteration.
	----------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <__msvc_ostream.hpp>
using namespace std;

int BinarySearch(const vector<int>& nums, int target)
{
	int left = 0;                            // Start of search space
	int right = static_cast<int>(nums.size()) - 1; // End of search space

	while (left <= right)
	{
		int mid = left + (right - left) / 2;  // Middle index, avoids overflow

		if (nums[mid] == target)
		{
			return mid; // Target found
		}
		else if (nums[mid] < target)
		{
			left = mid + 1; // Search in the right half
		}
		else
		{
			right = mid - 1; // Search in the left half
		}
	}

	// If we exit the loop, target was not found
	return -1;
}

int main()
{
	vector<int> nums = { -1, 0, 3, 5, 9, 12 };
	int target = 9;

	int index = BinarySearch(nums, target); // Expected output: 4

	if (index != -1)
	{
		cout << "Target " << target << " found at index: " << index << endl;
	}
	else
	{
		cout << "Target " << target << " not found." << endl;
	}

	nums = { -1, 0, 3, 5, 9, 12 };
	target = 2;
	index = BinarySearch(nums, target); // Expected output: -1 
	if (index != -1)
	{
		cout << "Target " << target << " found at index: " << index << endl;
	}
	else
	{
		cout << "Target " << target << " not found." << endl;
	}

	return 0;
}

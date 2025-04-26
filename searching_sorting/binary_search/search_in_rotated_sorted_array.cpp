/*
	Problem: Search in Rotated Sorted Array (LeetCode 33)

	Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length)
	such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
	For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
	Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums,
	or -1 if it is not in nums.

	You must write an algorithm with O(log n) runtime complexity.

	Example 1:
	Input: nums = [4,5,6,7,0,1,2], target = 0
	Output: 4

	Example 2:
	Input: nums = [4,5,6,7,0,1,2], target = 3
	Output: -1

	Example 3:
	Input: nums = [1], target = 0
	Output: -1

	----------------------------------------------------
	Idea:
	- The array is "half-sorted" at any point.
	- At every mid point, either the left half or the right half must be sorted.
	- Use that information to decide:
		- If left half is sorted, check if target lies within it.
		- Otherwise, search right half.
	- Repeat using standard binary search approach, but adjusted for rotation.

	Learning Highlights:
	- Time Complexity: O(log n)
	- Space Complexity: O(1)
	- Modified binary search based on sorted half detection.
	----------------------------------------------------
*/

#include <iostream>
#include <vector>
using namespace std;

int searchRotatedArray(const vector<int>& nums, int target)
{
	int left = 0;
	int right = static_cast<int>(nums.size()) - 1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2; // Safe mid calculation

		if (nums[mid] == target)
		{
			return mid; // Found target
		}

		// Determine which side is sorted
		if (nums[left] <= nums[mid])
		{
			// Left half is sorted
			if (nums[left] <= target && target < nums[mid])
			{
				right = mid - 1; // Target in left half
			}
			else
			{
				left = mid + 1; // Target in right half
			}
		}
		else
		{
			// Right half is sorted
			if (nums[mid] < target && target <= nums[right])
			{
				left = mid + 1; // Target in right half
			}
			else
			{
				right = mid - 1; // Target in left half
			}
		}
	}

	// Target not found
	return -1;
}

int main()
{
	vector<int> nums = { 4, 5, 6, 7, 0, 1, 2 };
	int target = 0;

	int index = searchRotatedArray(nums, target); //Expected output: 4

	if (index != -1)
	{
		cout << "Target " << target << " found at index: " << index << endl;
	}
	else
	{
		cout << "Target " << target << " not found." << endl;
	}

	nums = { 4, 5, 6, 7, 0, 1, 2 };
	target = 3;
	index = searchRotatedArray(nums, target); //Expected output: -1

	if (index != -1)
	{
		cout << "Target " << target << " found at index: " << index << endl;
	}
	else
	{
		cout << "Target " << target << " not found." << endl;
	}

	nums = { 1 };
	target = 0;
	index = searchRotatedArray(nums, target); //Expected output: -1

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

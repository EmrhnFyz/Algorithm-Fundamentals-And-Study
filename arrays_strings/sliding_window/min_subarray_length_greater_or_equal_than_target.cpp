/*
	Problem: Minimum Size Subarray Sum ≥ Target

	Given an array of positive integers nums and a positive integer target,
	return the minimal length of a contiguous subarray of which the sum is
	greater than or equal to target. If no such subarray exists, return 0.

	Example:

	Input: target = 7, nums = [2, 3, 1, 2, 4, 3]
	Output: 2
	Explanation: Subarray [4,3] has sum ≥ 7 and is the smallest such subarray.

	Input: target = 4, nums = [1,4,4]
	Output: 1

	Input: target = 11, nums = [1,1,1,1,1,1,1,1]
	Output: 0

	----------------------------------------------------
	Idea:
	- Use a variable-size sliding window.
	- Expand the window by moving `right` and adding to sum.
	- Once the sum is ≥ target, try shrinking the window from the left
	  to find the smallest valid window.
	- Track the minimum window length throughout the process.

	Learning Highlights:
	- Time Complexity: O(n), since each element is added and removed at most once.
	- Space Complexity: O(1), just tracking indices and the running sum.
	----------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <climits>
#include <utility>
#include <__msvc_ostream.hpp>
using namespace std;

int MinSubarrayLen(int target, const vector<int>& nums)
{
	int left = 0;              // Left boundary of the window
	int currentSum = 0;        // Sum of the current window
	int minLength = INT_MAX;  // Smallest length found (initialized to max)

	// Expand the window by moving the right pointer
	for (int right = 0; right < nums.size(); ++right)
	{
		currentSum += nums[right];  // Add current element to the sum

		// While the current window's sum is big enough, try to shrink it
		while (currentSum >= target)
		{
			// Update the minimum length if this window is smaller
			minLength = min(minLength, right - left + 1);

			// Shrink the window from the left
			currentSum -= nums[left];
			++left;
		}
	}

	// If no valid subarray was found, return 0
	return (minLength == INT_MAX) ? 0 : minLength;
}

int main()
{
	int target = 7;
	vector<int> nums = { 2, 3, 1, 2, 4, 3 };

	int result = MinSubarrayLen(target, nums);
	cout << "Minimum length of subarray with sum ≥ " << target << ": " << result << endl; // Expected: 2

	target = 4;
	nums = { 1, 4, 4 };

	result = MinSubarrayLen(target, nums);
	cout << "Minimum length of subarray with sum ≥ " << target << ": " << result << endl; // Expected: 1

	target = 11;
	nums = { 1, 1, 1, 1, 1, 1, 1, 1 };
	result = MinSubarrayLen(target, nums);
	cout << "Minimum length of subarray with sum ≥ " << target << ": " << result << endl; // Expected: 0

	return 0;
}

/*
	Problem: Maximum Subarray Sum (Kadane's Algorithm)

	Given an integer array nums, find the contiguous subarray (containing at least one number)
	which has the largest sum and return its sum.

	Example 1:

	Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
	Output: 6
	Explanation: The subarray [4,-1,2,1] has the largest sum 6.

	Example 2:
	Input: nums = [1]
	Output: 1
	Explanation: The subarray [1] has the largest sum 1.

	Example 3:
	Input: nums = [5,4,-1,7,8]
	Output: 23
	Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

	----------------------------------------------------
	Idea:
	- At each index, decide whether to:
		1. Start a new subarray from nums[i]
		2. Extend the previous subarray by adding nums[i] to currentSum
	- Keep track of:
		- currentSum = max subarray sum ending at current index
		- maxSum = overall max found so far

	Learning Highlights:
	- Time Complexity: O(n)
	- Space Complexity: O(1)
	- Works for negative values too
	----------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <utility>
#include <__msvc_ostream.hpp>
using namespace std;

int MaxSubArray(const vector<int>& nums)
{
	// Start both current and max sum at the first element
	int currentSum = nums[0];
	int maxSum = nums[0];

	// Iterate from second element to the end
	for (int i = 1; i < nums.size(); ++i)
	{
		// Decide: extend the previous subarray or start new from nums[i]
		currentSum = max(nums[i], currentSum + nums[i]);

		// Update maxSum if currentSum is bigger
		maxSum = max(maxSum, currentSum);
	}

	return maxSum;
}

int main()
{
	vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };

	int result = MaxSubArray(nums);
	cout << "Maximum subarray sum: " << result << endl; // Expected: 6

	nums = { 1 };
	result = MaxSubArray(nums);
	cout << "Maximum subarray sum: " << result << endl; // Expected: 1

	nums = { 5, 4, -1, 7, 8 };
	result = MaxSubArray(nums);
	cout << "Maximum subarray sum: " << result << endl; // Expected: 23



	return 0;
}

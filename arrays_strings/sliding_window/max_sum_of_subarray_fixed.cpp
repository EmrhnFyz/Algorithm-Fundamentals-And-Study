/*
	Problem: Max Sum of Subarray of Size K with Distinct Elements

	Given an array of integers and an integer k, find the maximum sum of any
	contiguous subarray of size k that contains only distinct elements.

	Example:
	Input: nums = [1,5,4,2,9,9,9], k = 3
	Output: 15
	Explanation: The subarrays of nums with length 3 are:
	- [1,5,4] which meets the requirements and has a sum of 10.
	- [5,4,2] which meets the requirements and has a sum of 11.
	- [4,2,9] which meets the requirements and has a sum of 15.
	- [2,9,9] which does not meet the requirements because the element 9 is repeated.
	- [9,9,9] which does not meet the requirements because the element 9 is repeated.
	We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions

	Input: nums = [4,4,4], k = 3
	Output: 0
	Explanation: The subarrays of nums with length 3 are:
	- [4,4,4] which does not meet the requirements because the element 4 is repeated.
	We return 0 because no subarrays meet the conditions.

	----------------------------------------------------
	Idea:
	- Use a sliding window to track subarrays of size at most `k`.
	- Use a hash set to make sure all elements in the current window are unique.
	- If a duplicate is found, shrink the window from the left until the duplicate is removed.
	- Only check/update the max sum when the window size is exactly `k`.

	Learning Highlights:
	- Combines fixed-size window logic with uniqueness constraint.
	- Time Complexity: O(n)
	  Each element enters and exits the window at most once.
	- Space Complexity: O(k) due to hash set and window tracking.
	----------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>
#include <__msvc_ostream.hpp>
using namespace std;

int MaxSumDistinctK(const vector<int>& nums, int k)
{
	unordered_set<int> windowSet;  // Tracks distinct elements in current window
	int left = 0;                  // Left boundary of sliding window
	int windowSum = 0;             // Sum of current window
	int maxSum = 0;                // Max sum found so far

	for (int right = 0; right < nums.size(); ++right)
	{
		// If nums[right] already exists in the window,
		// shrink window from the left until it's removed
		while (windowSet.count(nums[right]))
		{
			windowSet.erase(nums[left]);     // Remove leftmost element from set
			windowSum -= nums[left];         // Subtract its value from current sum
			++left;                          // Move left pointer forward
		}

		// Add the current element to the window
		windowSet.insert(nums[right]);
		windowSum += nums[right];

		// If the window size becomes exactly k, check for max sum
		if (right - left + 1 == k)
		{
			maxSum = max(maxSum, windowSum); // Update maxSum if needed

			// Shrink the window by removing the leftmost element
			// so we can start a new window in the next iteration
			windowSet.erase(nums[left]);
			windowSum -= nums[left];
			++left;
		}
	}

	return maxSum;
}

int main()
{
	vector<int> nums = { 1, 5, 4, 2, 9, 9, 9 };
	int k = 3;

	int result = MaxSumDistinctK(nums, k);
	cout << "Max sum of subarray of size " << k << " with distinct elements: " << result << endl; // Expected: 15

	nums = { 4, 4, 4 };
	k = 3;
	result = MaxSumDistinctK(nums, k);
	cout << "Max sum of subarray of size " << k << " with distinct elements: " << result << endl; // Expected: 0

	return 0;
}

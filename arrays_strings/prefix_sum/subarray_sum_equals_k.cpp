/*
	Problem: Subarray Sum Equals K (LeetCode 560)

	Given an array of integers and an integer k, find the total number of
	continuous subarrays whose sum equals to k.

	Example 1:
	Input: nums = [1,1,1], k = 2
	Output: 2

	Example 2:
	Input: nums = [1,2,3], k = 3
	Output: 2

	----------------------------------------------------
	Idea:
	- We use a prefix sum + hash map to track how many times a specific
	  prefix sum has occurred so far.
	- For each element, calculate runningSum.
	  We want to find how many times (runningSum - k) has appeared before.
	  That tells us there exists a subarray that ends at this index with sum k.
	- Count those matches.

	Learning Highlights:
	- Time Complexity: O(n)
	- Space Complexity: O(n) for the hash map
	- This is a super elegant trick using math + hash maps
	----------------------------------------------------
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <__msvc_ostream.hpp>
using namespace std;

int SubarraySum(const vector<int>& nums, int k)
{
	int arraySize = nums.size();
	unordered_map<int, int> prefixCount; // Map: runningSum -> count of times it has occurred
	prefixCount[0] = 1; // Base case: a prefix sum of 0 occurs once (empty subarray)

	int runningSum = 0; // Cumulative sum from index 0 to current
	int count = 0;      // Total number of matching subarrays

	for (int i = 0; i < arraySize; ++i)
	{
		runningSum += nums[i]; // Update running sum with current element

		// Check if (runningSum - k) has been seen before
		// If so, it means a subarray ending here sums to k
		if (prefixCount.count(runningSum - k))
		{
			count += prefixCount[runningSum - k];
		}

		// Record current running sum in the map
		prefixCount[runningSum]++;
	}

	return count;
}

int main()
{
	vector<int> nums = { 1, 1, 1 };
	int k = 2;

	int result = SubarraySum(nums, k);
	cout << "Number of subarrays with sum = " << k << ": " << result << endl; // Expected: 2

	nums = { 1, 2, 3 };
	k = 3;
	result = SubarraySum(nums, k);
	cout << "Number of subarrays with sum = " << k << ": " << result << endl; // Expected: 2

	return 0;
}

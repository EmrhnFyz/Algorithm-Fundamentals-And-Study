/*
	Problem: Two Sum (Unsorted Array)

	Given an unsorted array of integers and a target value, return the indices
	(0-based) of the two numbers such that they add up to the target.

	Constraints:
	- Exactly one solution exists
	- Elements are not necessarily sorted

	Example:
	Input: nums = [3, 2, 4], target = 6
	Output: [1, 2]
	----------------------------------------------------
	Learning Highlights:
	- Use a hash map to track values we've seen so far.
	- For each number, calculate the complement and check if it's already seen.
	- Time Complexity: O(n), Space Complexity: O(n)
	- This version works on unsorted arrays and is interview-friendly.
	----------------------------------------------------
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <__msvc_ostream.hpp>
using namespace std;

vector<int> TwoSumUnsorted(const vector<int>& nums, int target)
{
	unordered_map<int, int> seen; // Stores {value: index} for quick lookup

	for (int i = 0; i < nums.size(); ++i)
	{
		int current = nums[i];
		int complement = target - current; // What number do we need to reach the target?

		// If the complement was already seen, we found the pair
		if (seen.count(complement))
		{
			return { seen[complement], i };
		}

		// Otherwise, store the current number with its index
		seen[nums[i]] = i;
	}

	return {}; // Should never reach here if exactly one solution exists
}

int main()
{
	vector<int> nums = { 3, 2, 4 };
	int target = 6;

	vector<int> result = TwoSumUnsorted(nums, target);
	cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;

	return 0;
}

/*
	Problem: Two Sum (Sorted Array)

	Given a sorted array of integers and a target value, return the indices
	of the two numbers such that they add up to the target.

	Constraints:
	- Exactly one solution exists
	- The array is sorted in ascending order

	Example:
	Input: nums = [2, 7, 11, 15], target = 9
	Output: [0, 1]

	----------------------------------------------------
	Learning Highlights:
	- Use two pointers from both ends when the array is sorted.
	- If sum is too small, move left pointer rightward to increase it.
	- If sum is too large, move right pointer leftward to decrease it.
	- Time Complexity: O(n), Space Complexity: O(1)
	- Elegant and efficient: each value is considered only once.
	----------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <__msvc_ostream.hpp>
using namespace std;

vector<int> TwoSumSorted(const vector<int>& nums, int target)
{
	int left = 0; // Starts from the start of the array
	int right = nums.size() - 1; // Starts from the end of the array

	while (left < right)
	{
		int sum = nums[left] + nums[right];

		if (sum == target)
		{
			return { left, right }; // sum == target, return indices
		}
		else if (sum < target)
		{
			++left;	// Need a larger sum -> move the left pointer to the right
		}
		else  // Need a smaller sum -> move the right pointer to the left
		{
			--right;
		}
	}

	return {}; // Should never reach here if exactly one solution exists
}

int main()
{
	vector<int> nums = { 2, 7, 11, 15 };
	int target = 9;

	vector<int> result = TwoSumSorted(nums, target);
	cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;

	return 0;
}

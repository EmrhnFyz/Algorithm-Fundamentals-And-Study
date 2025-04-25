/*
	Problem: Range Sum Query - Immutable (LeetCode 303)

	Given an integer array nums, handle multiple queries of the following type:
	Return the sum of the elements of nums between indices left and right inclusive.

	Example 1:

	Input
	["NumArray", "sumRange", "sumRange", "sumRange"]
	[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
	Output
	[null, 1, -1, -3]

	Explanation
	NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
	numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
	numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
	numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3


	----------------------------------------------------
	Idea:
	- Use a prefix sum array where prefix[i] = sum of nums[0] to nums[i - 1]
	- This allows us to compute the sum from index `left` to `right` as:
		sum = prefix[right + 1] - prefix[left]

	Learning Highlights:
	- Time Complexity:
		- Constructor: O(n)
		- sumRange query: O(1)
	- Space Complexity: O(n) for prefix sum array
	----------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <__msvc_ostream.hpp>
using namespace std;

class NumArray
{
private:
	vector<int> prefix; // prefix[i] stores sum of nums[0...i-1]

public:
	// Constructor to initialize and build prefix sum
	NumArray(const vector<int>& nums)
	{
		// We create a prefix array of size n+1 with all values initialized to 0
		// prefix[0] = 0, and prefix[i + 1] = sum of first i elements in nums
		prefix.resize(nums.size() + 1, 0);

		for (int i = 0; i < nums.size(); ++i)
		{
			prefix[i + 1] = prefix[i] + nums[i];  // cumulative sum
			// prefix[1] = nums[0]
			// prefix[2] = nums[0] + nums[1]
			// ...
		}
	}

	// Returns the sum of elements from index 'left' to 'right' (inclusive)
	int sumRange(int left, int right)
	{
		// Example: sum of nums[2] to nums[4] = prefix[5] - prefix[2]
		return prefix[right + 1] - prefix[left];
	}
};

int main()
{
	// Example usage from LeetCode
	NumArray numArray({ -2, 0, 3, -5, 2, -1 });

	cout << "sumRange(0, 2): " << numArray.sumRange(0, 2) << endl; // 1
	cout << "sumRange(2, 5): " << numArray.sumRange(2, 5) << endl; // -1
	cout << "sumRange(0, 5): " << numArray.sumRange(0, 5) << endl; // -3

	return 0;
}

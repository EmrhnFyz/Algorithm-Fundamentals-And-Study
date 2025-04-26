/*
	Problem: Counting Sort

	Given an array of non-negative integers where the maximum value is not too large,
	sort the array using the Counting Sort algorithm.

	Example:
	Input: nums = [5, 2, 9, 1, 5, 6]
	Output: [1, 2, 5, 5, 6, 9]

	----------------------------------------------------
	Idea:
	- Counting Sort counts the number of occurrences of each distinct element.
	- Then reconstructs the sorted array based on these counts.

	Learning Highlights:
	- Time Complexity: O(n + k) where n = number of elements, k = range of input values.
	- Space Complexity: O(k) extra space for counting array.
	- Stable if implemented carefully.
	- Best for small integer ranges.

	----------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <__msvc_ostream.hpp>
using namespace std;

void CountingSort(vector<int>& nums)
{
	if (nums.empty())
	{
		return; // Handle empty input
	}

	// Step 1: Find the maximum value to determine count array size
	int maxVal = *max_element(nums.begin(), nums.end());

	// Step 2: Initialize count array with zeros
	vector<int> count(maxVal + 1, 0);

	// Step 3: Count occurrences of each number
	for (int num : nums)
	{
		count[num]++;
	}

	// Step 4: Reconstruct the sorted array
	int index = 0;
	for (int num = 0; num <= maxVal; ++num)
	{
		while (count[num] > 0)
		{
			nums[index++] = num;
			count[num]--;
		}
	}
}

int main()
{
	vector<int> nums = { 5, 2, 9, 1, 5, 6 };

	cout << "Original array: ";
	for (int num : nums)
	{
		cout << num << " ";
	}
	cout << endl;

	CountingSort(nums);

	cout << "Sorted array: ";
	for (int num : nums)
	{
		cout << num << " ";
	}
	cout << endl;

	return 0;
}

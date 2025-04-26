/*
	Problem: Radix Sort

	Given an array of non-negative integers, sort the array in ascending order using Radix Sort.

	Example:
	Input: nums = [170, 45, 75, 90, 802, 24, 2, 66]
	Output: [2, 24, 45, 66, 75, 90, 170, 802]

	----------------------------------------------------
	Idea:
	- Radix Sort processes numbers digit by digit starting from the least significant digit (LSD).
	- It uses a **stable** sub-sorting algorithm (like Counting Sort) at each digit place.
	- Numbers are grouped and reassembled based on each digit without direct comparisons.

	Learning Highlights:
	- Time Complexity: O(d × (n + k)), where
		- d = number of digits in the maximum number,
		- n = number of elements,
		- k = range of digits (typically 0-9).
	- Space Complexity: O(n + k) for temporary arrays during counting.
	- Works best for numbers with a fixed, limited number of digits.

	----------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <algorithm> // for max_element
using namespace std;

// Helper function to perform counting sort based on a specific digit place
void CountingSortByDigit(vector<int>& nums, int place)
{
	int n = static_cast<int>(nums.size());
	vector<int> output(n);          // Output array to store sorted order
	vector<int> count(10, 0);        // Count array for digits 0-9

	// Step 1: Count occurrences of each digit at 'place'
	for (int num : nums)
	{
		int digit = (num / place) % 10;
		count[digit]++;
	}

	// Step 2: Change count[i] to be the actual position of this digit in output[]
	for (int i = 1; i < 10; ++i)
	{
		count[i] += count[i - 1];
	}

	// Step 3: Build the output array (go backwards for stable sort)
	for (int i = n - 1; i >= 0; --i)
	{
		int digit = (nums[i] / place) % 10;
		output[count[digit] - 1] = nums[i];
		count[digit]--;
	}

	// Step 4: Copy the output array back to nums
	nums = output;
}

// Main Radix Sort function
void RadixSort(vector<int>& nums)
{
	if (nums.empty())
	{
		return;
	}

	// Find the maximum number to know the number of digits
	int maxNum = *max_element(nums.begin(), nums.end());

	// Apply counting sort for each digit place (1s, 10s, 100s, ...)
	for (int place = 1; maxNum / place > 0; place *= 10)
	{
		CountingSortByDigit(nums, place);
	}
}

int main()
{
	vector<int> nums = { 170, 45, 75, 90, 802, 24, 2, 66 };

	cout << "Original array: ";
	for (int num : nums)
	{
		cout << num << " ";
	}
	cout << endl;

	RadixSort(nums);

	cout << "Sorted array: ";
	for (int num : nums)
	{
		cout << num << " ";
	}
	cout << endl;

	return 0;
}

/*
	Problem: Merge Sort

	Given an array of integers, sort the array in ascending order using the Merge Sort algorithm.

	Example:
	Input: nums = [5, 2, 9, 1, 5, 6]
	Output: [1, 2, 5, 5, 6, 9]

	----------------------------------------------------
	Idea:
	- Merge Sort follows a "divide and conquer" strategy:
		1. Divide the array into two halves.
		2. Recursively sort each half.
		3. Merge the two sorted halves into one sorted array.

	 Learning Highlights:
	- Time Complexity: O(n log n) — divide in log n steps, merge n elements at each level.
	- Space Complexity: O(n) — additional space for merged arrays.
	- Stable Sort: maintains relative order of equal elements.
	- Good for large datasets or when stability matters.

	----------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <__msvc_ostream.hpp>
using namespace std;

// Helper function to merge two sorted halves
void Merge(vector<int>& nums, int left, int mid, int right)
{
	// Create temporary arrays for left and right halves
	vector<int> leftArray(nums.begin() + left, nums.begin() + mid + 1);
	vector<int> rightArray(nums.begin() + mid + 1, nums.begin() + right + 1);

	int i = 0; // Index for leftArray
	int j = 0; // Index for rightArray
	int k = left; // Index for merged nums array

	// Merge elements back into nums
	while (i < static_cast<int>(leftArray.size()) && j < static_cast<int>(rightArray.size()))
	{
		if (leftArray[i] <= rightArray[j])
		{
			nums[k++] = leftArray[i++];
		}
		else
		{
			nums[k++] = rightArray[j++];
		}
	}

	// Copy any remaining elements
	while (i < static_cast<int>(leftArray.size()))
	{
		nums[k++] = leftArray[i++];
	}
	while (j < static_cast<int>(rightArray.size()))
	{
		nums[k++] = rightArray[j++];
	}
}

// Recursive function to apply merge sort
void MergeSort(vector<int>& nums, int left, int right)
{
	if (left >= right)
	{
		return; // Base case: one element is already sorted
	}

	int mid = left + (right - left) / 2; // Find the midpoint

	// Sort left half
	MergeSort(nums, left, mid);

	// Sort right half
	MergeSort(nums, mid + 1, right);

	// Merge the two sorted halves
	Merge(nums, left, mid, right);
}

int main()
{
	vector<int> nums = { 10, 5, 1, 3 ,2, 9, 7, 1, 9, 8, 5, 6 };

	cout << "Original array: ";
	for (int num : nums) cout << num << " ";
	cout << endl;

	MergeSort(nums, 0, static_cast<int>(nums.size()) - 1);

	cout << "Sorted array: ";
	for (int num : nums) cout << num << " ";
	cout << endl;

	return 0;
}

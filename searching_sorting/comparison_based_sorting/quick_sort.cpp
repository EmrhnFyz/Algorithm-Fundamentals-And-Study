/*
	Problem: Quick Sort

	Given an array of integers, sort the array in ascending order using the Quick Sort algorithm.

	Example:
	Input: nums = [5, 2, 9, 1, 5, 6]
	Output: [1, 2, 5, 5, 6, 9]

	----------------------------------------------------
	Idea:
	- Quick Sort follows a "divide and conquer" strategy:
		1. Choose a pivot element.
		2. Partition the array: elements less than pivot to the left, greater to the right.
		3. Recursively sort the left and right parts.
	- Pivot choice is crucial — bad pivots cause poor performance.

	Learning Highlights:
	- Time Complexity:
		- Average case: O(n log n)
		- Worst case: O(n²) (e.g., sorted arrays with bad pivots)
	- Space Complexity: O(log n) recursion stack
	- In-place sorting: no extra array needed.
	- Fast in practice when pivot choice is reasonable.

	----------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <utility>
#include <__msvc_ostream.hpp>
using namespace std;

// Partition function (Lomuto partition scheme)
int Partition(vector<int>& nums, int low, int high)
{
	int pivot = nums[high]; // Choose the last element as pivot
	int i = low - 1;        // Place for swapping smaller elements

	for (int j = low; j < high; ++j)
	{
		if (nums[j] < pivot)
		{
			++i;
			swap(nums[i], nums[j]); // Move smaller elements to the left
		}
	}

	// Place pivot in the correct position
	swap(nums[i + 1], nums[high]);
	return i + 1; // Return pivot's final position
}

// Recursive Quick Sort
void QuickSort(vector<int>& nums, int low, int high)
{
	if (low < high)
	{
		int pivotIndex = Partition(nums, low, high); // Partition and get pivot position

		QuickSort(nums, low, pivotIndex - 1);  // Sort left part
		QuickSort(nums, pivotIndex + 1, high); // Sort right part
	}
}

int main()
{
	vector<int> nums = { 5, 2, 9, 1, 5, 6 };

	cout << "Original array: ";
	for (int num : nums) cout << num << " ";
	cout << endl;

	QuickSort(nums, 0, static_cast<int>(nums.size()) - 1);

	cout << "Sorted array: ";
	for (int num : nums) cout << num << " ";
	cout << endl;

	return 0;
}

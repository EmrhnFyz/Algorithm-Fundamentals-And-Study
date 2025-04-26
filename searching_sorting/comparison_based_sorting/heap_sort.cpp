/*
	Problem: Heap Sort

	Given an array of integers, sort the array in ascending order using the Heap Sort algorithm.

	Example:
	Input: nums = [5, 2, 9, 1, 5, 6]
	Output: [1, 2, 5, 5, 6, 9]

	----------------------------------------------------
	Idea:
	- Heap Sort uses a heap data structure (specifically, a Max-Heap).
	- Steps:
		1. Build a max-heap from the array.
		2. Swap the first element (max) with the last unsorted element.
		3. Reduce the heap size and heapify again.
	- Repeat until the heap size is reduced to 1.

	Learning Highlights:
	- Time Complexity: O(n log n) for both building the heap and repeated heapify operations.
	- Space Complexity: O(1) (in-place sorting, no extra arrays needed).
	- Heap Sort is **not stable** (order of equal elements might not be preserved).
	----------------------------------------------------
*/

#include <iostream>
#include <vector>
using namespace std;

// Helper function to maintain max-heap property
void Heapify(vector<int>& nums, int n, int i)
{
	int largest = i;         // Assume current i is largest
	int left = 2 * i + 1;     // Left child index
	int right = 2 * i + 2;    // Right child index

	// If left child exists and is greater than root
	if (left < n && nums[left] > nums[largest])
	{
		largest = left;
	}

	// If right child exists and is greater than largest so far
	if (right < n && nums[right] > nums[largest])
	{
		largest = right;
	}

	// If largest is not root
	if (largest != i)
	{
		swap(nums[i], nums[largest]); // Swap root with largest
		Heapify(nums, n, largest);    // Recursively heapify the affected subtree
	}
}

// Main Heap Sort function
void HeapSort(vector<int>& nums)
{
	int n = static_cast<int>(nums.size());

	// Step 1: Build a max heap
	for (int i = n / 2 - 1; i >= 0; --i)
	{
		Heapify(nums, n, i);
	}

	// Step 2: Extract elements from heap one by one
	for (int i = n - 1; i > 0; --i)
	{
		swap(nums[0], nums[i]);     // Move current root to end
		Heapify(nums, i, 0);         // Heapify reduced heap
	}
}

int main()
{
	vector<int> nums = { 5, 2, 9, 1, 5, 6 };

	cout << "Original array: ";
	for (int num : nums) cout << num << " ";
	cout << endl;

	HeapSort(nums);

	cout << "Sorted array: ";
	for (int num : nums) cout << num << " ";
	cout << endl;

	return 0;
}

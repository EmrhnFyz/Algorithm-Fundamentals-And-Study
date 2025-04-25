/*
	Problem: Container With Most Water

	Given an array of heights, where each element represents the height of a vertical line
	drawn at that index, find two lines that together with the x-axis form a container
	that holds the most water.

	The area is calculated as:
		area = min(height[left], height[right]) * (right - left)

	Example:
	Input: heights = [1,8,6,2,5,4,8,3,7]
	Output: 49
	Explanation:
	- Lines at index 1 (height 8) and index 8 (height 7) form a container.
	- Width = 8 - 1 = 7
	- Height = min(8, 7) = 7
	- Area = 7 * 7 = 49

	----------------------------------------------------
	Learning Highlights:
	- Use two pointers: one at the beginning, one at the end.
	- The height is limited by the shorter of the two lines.
	- Move the pointer pointing to the shorter line to potentially increase area.
	- Time Complexity: O(n), Space Complexity: O(1)
	- Greedy + opposing pointers: optimal and efficient.
	----------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <utility>
#include <__msvc_ostream.hpp>
using namespace std;

int MaxArea(const vector<int>& height)
{
	int left = 0;
	int right = height.size() - 1;
	int maxArea = 0;

	// Loop until the two pointers meet
	while (left < right)
	{
		// Calculate width and the height of the shorter line
		int width = right - left;
		int minHeight = min(height[left], height[right]);

		// Calculate area and update maxArea if needed
		int area = width * minHeight;
		maxArea = max(maxArea, area);

		// Move the pointer pointing to the shorter line
		if (height[left] < height[right])
		{
			++left;
		}
		else
		{
			--right;
		}
	}

	return maxArea;
}

int main()
{
	vector<int> heights = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	int result = MaxArea(heights);

	cout << "Maximum area: " << result << endl;
	return 0;
}

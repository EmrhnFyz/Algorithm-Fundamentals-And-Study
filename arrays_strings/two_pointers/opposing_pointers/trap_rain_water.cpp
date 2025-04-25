/*
	Problem: Trapping Rain Water

	Given n non-negative integers representing an elevation map where the width of each bar is 1,
	compute how much water it can trap after raining.

	Example:
	Input:  height = [0,1,0,2,1,0,1,3,2,1,2,1]
	Output: 6

	Explanation:
	Water is trapped between bars based on the minimum of the max height on the left and right.
	The two-pointer solution avoids the need for extra arrays.

	----------------------------------------------------
	Learning Highlights:
	- Use two pointers (`left`, `right`) and track `leftMax` and `rightMax`.
	- Water trapped at a position = min(leftMax, rightMax) - currentHeight
	- Only move the pointer with the smaller wall, because that side is the limiting factor.
	- Time Complexity: O(n), Space Complexity: O(1)
	----------------------------------------------------

	Idea:
	- Water can only be trapped where there are taller bars on both sides.
	- Use two pointers (`left`, `right`) to scan inward.
	- Maintain the highest bar seen from the left (`leftMax`) and right (`rightMax`).
	- At each step, determine which side has the shorter bar.
		- Only the shorter side can act as a limiting wall for trapping water.
	- If current height < max on that side, we can trap water at that position.
	- Move inward from the side that is shorter and repeat.
*/


#include <iostream>
#include <vector>
#include <__msvc_ostream.hpp>
using namespace std;

int Trap(const vector<int>& height)
{
	int left = 0;
	int right = height.size() - 1;
	int leftMax = 0, rightMax = 0;
	int totalWater = 0;

	while (left < right)
	{
		// Compare left and right heights to decide which side to move
		if (height[left] < height[right])
		{
			if (height[left] >= leftMax)
			{
				leftMax = height[left]; // Update max height on the left
			}
			else
			{
				totalWater += leftMax - height[left]; // Water is trapped
			}
			++left; // Move inward
		}
		else
		{
			if (height[right] >= rightMax)
			{
				rightMax = height[right]; // Update max height on the right
			}
			else
			{
				totalWater += rightMax - height[right]; // Water is trapped
			}
			--right; // Move inward
		}
	}

	return totalWater;
}

int main()
{
	vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };

	int result = Trap(height);
	cout << "Total trapped water: " << result << endl; // Expected: 6

	return 0;
}

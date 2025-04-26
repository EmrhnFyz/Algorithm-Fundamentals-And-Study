/*
	Problem: Binary Search on Answer Space

	Instead of searching directly on the array, we search on the RANGE of possible answers.

	Example Problem (conceptual):
	- Given an array of packages' weights and days D,
	  find the minimum capacity of a ship to deliver all packages within D days.
	- Another example: find the smallest divisor for which the array sum of divisions <= threshold.

	----------------------------------------------------
	Idea:
	- Define the "answer space" — the range of possible answers (e.g., min capacity to max capacity).
	- Use binary search over this range:
		- Check a middle candidate (e.g., mid capacity).
		- Test: is this candidate valid? (e.g., can we ship in D days?)
		- If yes, try smaller; if no, try bigger.
	- **The key**: the decision function (isValid) must be monotonic (once true/false, stays that way).

	Learning Highlights:
	- Time Complexity: O(log(maxAnswer - minAnswer) × checkTime)
	- Space Complexity: O(1)
	- Powerful in optimization/feasibility problems.
	----------------------------------------------------
*/

#include <iostream>
#include <vector>
using namespace std;

// Example helper: can we ship all packages within 'days' given 'capacity'?
bool CanShipWithCapacity(const vector<int>& weights, int days, int capacity)
{
	int daysNeeded = 1; // Start with 1 day
	int currentLoad = 0;

	for (int weight : weights)
	{
		if (currentLoad + weight > capacity)
		{
			// Need a new day
			++daysNeeded;
			currentLoad = 0;
		}
		currentLoad += weight;
	}

	return daysNeeded <= days;
}

int MinShipCapacity(const vector<int>& weights, int days)
{
	int left = *max_element(weights.begin(), weights.end()); // Minimum possible capacity
	int right = 0;

	for (int weight : weights)
	{
		right += weight;                        // Maximum possible capacity
	}

	int answer = right; // Start with max and minimize

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (CanShipWithCapacity(weights, days, mid))
		{
			answer = mid;      // Mid is valid, try smaller
			right = mid - 1;
		}
		else
		{
			left = mid + 1;    // Mid too small, need bigger capacity
		}
	}

	return answer;
}

int main()
{
	vector<int> weights = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int days = 5;

	int result = MinShipCapacity(weights, days);
	cout << "Minimum ship capacity to deliver in " << days << " days: " << result << endl;
	// Expected: 15

	return 0;
}

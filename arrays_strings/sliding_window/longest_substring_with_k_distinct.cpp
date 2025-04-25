/*
	Problem: Longest Substring with K Distinct Characters

	Given a string s and an integer k, return the length of the longest substring
	that contains at most k distinct characters.

	Example:
	Input: s = "eceba", k = 2
	Output: 3
	Explanation: "ece" is the longest substring with 2 distinct characters.

	----------------------------------------------------
	 Idea:
	- Use the variable-size sliding window technique.
	- Expand the window by moving the `right` pointer forward.
	- Track character frequencies in the window using a hash map.
	- If the number of distinct characters exceeds `k`, shrink the window from the left
	  until the condition is met again.
	- Update the max length whenever the current window is valid.

	Learning Highlights:
	- Variable-size sliding window pattern
	- Use a hash map to count character frequencies
	- Shrink the window when the number of distinct characters exceeds k
	- Time Complexity: O(n), Space Complexity: O(k)
	----------------------------------------------------
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <__msvc_ostream.hpp>
using namespace std;

int LengthOfLongestSubstringKDistinct(const string& s, int k)
{
	unordered_map<char, int> freq; // Tracks frequency of characters in the current window
	int left = 0; // Left boundary of the window
	int maxLen = 0;  // Result: longest valid window length found so far

	// Expand the window using the right pointer
	for (int right = 0; right < s.size(); ++right)
	{
		char c = s[right];
		freq[c]++;  // Include the current character in the window

		// Shrink the window from the left if we have more than k distinct characters
		while (freq.size() > k)
		{
			char leftChar = s[left];
			freq[leftChar]--; // Decrease count of the leftmost character


			// If its count drops to 0, remove it from the map
			if (freq[leftChar] == 0)
			{
				freq.erase(leftChar);
			}

			++left; // Move the left pointer rightward to shrink the window
		}

		// Update the result with the size of the current valid window
		maxLen = max(maxLen, right - left + 1);
	}

	return maxLen;
}

int main()
{
	string s = "eceba";
	int k = 2;

	int result = LengthOfLongestSubstringKDistinct(s, k);
	cout << "Longest substring with " << k << " distinct characters: " << result << endl; // Expected: 3

	return 0;
}

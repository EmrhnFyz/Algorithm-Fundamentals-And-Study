/*
	Problem: Reverse String

	Write a function that reverses a string in-place.
	The input is given as a vector of characters `s`.

	Example:
	Input:  ['h','e','l','l','o']
	Output: ['o','l','l','e','h']

	----------------------------------------------------
	Learning Highlights:
	- Classic opposing pointers pattern: swap from ends inward.
	- Modify the string in-place using a while loop.
	- Time Complexity: O(n), Space Complexity: O(1)
	----------------------------------------------------
*/

#include <iostream>
#include <vector>
using namespace std;

void ReverseString(vector<char>& s)
{
	int left = 0;
	int right = static_cast<int>(s.size()) - 1;

	// Swap characters from both ends inward
	while (left < right)
	{
		swap(s[left], s[right]); // Swap characters
		++left;
		--right;
	}
}

int main()
{
	vector<char> s = { 'h', 'e', 'l', 'l', 'o' };

	ReverseString(s);

	cout << "Reversed string: ";
	for (char c : s)
	{
		cout << c;
	}
	cout << endl;

	return 0;
}

/*
	Problem: Valid Palindrome

	A phrase is a palindrome if, after converting all uppercase letters into lowercase
	and removing all non-alphanumeric characters, it reads the same forward and backward.

	Example:
	Input: "A man, a plan, a canal: Panama"
	Output: true

	Input: "";
	Output: true

	Input: "race a car"
	Output: false

	Explanation:
	- Normalize: "amanaplanacanalpanama"
	- It's the same forward and backward -> true

	- Normalize: "";
	- It's empty, compare with itself -> true;

	-Normalize: "raceacar"
	- It's not the same forward and backward -> false

	----------------------------------------------------
	Learning Highlights:
	- Classic use case of two pointers on a string.
	- Skip non-alphanumeric characters using isalnum().
	- Compare lowercase versions of characters using tolower().
	- Time Complexity: O(n), Space Complexity: O(1)
	----------------------------------------------------
*/

#include <iostream>
#include <string>
#include <cctype>
#include <__msvc_ostream.hpp>
using namespace std;

bool isPalindrome(const string& s)
{
	int left = 0;
	int right = static_cast<int>(s.size()) - 1;

	while (left < right)
	{
		// Skip non-alphanumeric characters from the left
		while (left < right && !isalnum(s[left]))
		{
			++left;
		}

		// Skip non-alphanumeric characters from the right
		while (left < right && !isalnum(s[right]))
		{
			--right;
		}

		// Compare characters case-insensitively
		if (tolower(s[left]) != tolower(s[right]))
		{
			return false; // Mismatch found
		}

		++left;
		--right;
	}

	return true; // All matched
}

int main()
{
	string input1 = "A man, a plan, a canal: Panama";
	string input2 = "";
	string input3 = "race a car";

	bool result1 = isPalindrome(input1);
	bool result2 = isPalindrome(input2);
	bool result3 = isPalindrome(input3);

	cout << "Is \"" << input1 << "\" a palindrome? " << (result1 ? "true" : "false") << endl;
	cout << "Is \"" << input2 << "\" a palindrome? " << (result2 ? "true" : "false") << endl;
	cout << "Is \"" << input3 << "\" a palindrome? " << (result3 ? "true" : "false") << endl;

	return 0;
}

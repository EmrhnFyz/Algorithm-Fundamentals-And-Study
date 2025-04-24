#include <__msvc_ostream.hpp>
#include <cassert>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

static void PrintNumbers(const vector<int>& numbers, const string& prefix)
{
	cout << prefix;
	for (int value : numbers)
	{
		cout << value << ' ';
	}
	cout << endl;
}

int main()
{
	// Sample data
	vector<int> numbers = { 1, 2, 3, 4, 5 };
	PrintNumbers(numbers, "Original numbers: ");

	// 1) Swap two elements
	int firstIndex = 0;
	int secondIndex = 4;
	swap(numbers[firstIndex], numbers[secondIndex]);
	PrintNumbers(numbers, "After swap (firstIndex, secondIndex): ");

	// 2) Use std::reverse to reverse entire vector
	reverse(numbers.begin(), numbers.end());
	PrintNumbers(numbers, "After std::reverse: ");

	// 3) Manual reverse using two pointers
	vector<int> manual = { 1, 2, 3, 4, 5 };
	PrintNumbers(manual, "Manual reverse start: ");
	int leftPointer = 0;
	int rightPointer = static_cast<int>(manual.size()) - 1;
	while (leftPointer < rightPointer)
	{
		swap(manual[leftPointer], manual[rightPointer]);
		++leftPointer;
		--rightPointer;
	}
	PrintNumbers(manual, "Manual reverse result: ");

	// 4) Assertion to check pointers ended correctly
	assert(leftPointer == rightPointer || leftPointer == rightPointer + 1);
	cout << "Assertion passed for manual reverse pointers." << endl;

	return 0;
}

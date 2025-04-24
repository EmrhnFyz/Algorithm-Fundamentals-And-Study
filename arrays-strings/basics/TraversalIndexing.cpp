#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int main() {
    // Sample data
    vector<int> numbers = {1, 2, 3, 4, 5};

    // 1) Forward traversal using indexed loop
    cout << "Forward traversal (indexed): ";
    for (int index = 0; index < static_cast<int>(numbers.size()); ++index) {
        cout << numbers[index] << ' ';
    }
    cout << endl;

    // 2) Range-based for loop (C++11+)
    cout << "Forward traversal (range-based): ";
    for (int value : numbers) {
        cout << value << ' ';
    }
    cout << endl;

    // 3) Reverse traversal using indexed loop
    cout << "Reverse traversal: ";
    for (int index = static_cast<int>(numbers.size()) - 1; index >= 0; --index) {
        cout << numbers[index] << ' ';
    }
    cout << endl;

    // 4) Safe random access with bounds checking
    int targetIndex = 2;
    cout << "Access at targetIndex = " << targetIndex << ": ";
    if (targetIndex >= 0 && targetIndex < static_cast<int>(numbers.size())) {
        cout << numbers[targetIndex] << endl;
    } else {
        cout << "Error: index out of bounds" << endl;
    }

    // 5) Demonstrate assertion for safe access in debug builds
    int safeIndex = 4;
    assert(safeIndex >= 0 && safeIndex < static_cast<int>(numbers.size()));
    cout << "Assertion passed, numbers[safeIndex] = " << numbers[safeIndex] << endl;

    return 0;
}

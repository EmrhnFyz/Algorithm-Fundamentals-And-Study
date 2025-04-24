# Basics & Pitfalls

## 1. Traversal & Indexing

### Forward Traversal
```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<int> numbers = {1, 2, 3, 4};
for (int index = 0; index < static_cast<int>(numbers.size()); ++index) {
    cout << numbers[index] << ' ';
}
// Output: 1 2 3 4
```

### Range-based Loop
```cpp
for (int value : numbers) {
    cout << value << ' ';
}
// Output: 1 2 3 4
```

### Safe Access with Bounds Checking
```cpp
int targetIndex = 2;
if (targetIndex >= 0 && targetIndex < static_cast<int>(numbers.size())) {
    cout << numbers[targetIndex];
} else {
    // handle out-of-bounds case
}
```

> **Pitfall:** Off-by-one in loop conditions (using `<= size()` instead of `< size()`).

---

## 2. In-place Swapping & Reversing

### Swapping Two Elements
```cpp
int firstIndex = 0;
int secondIndex = 3;
swap(numbers[firstIndex], numbers[secondIndex]);
```

### Using `std::reverse`
```cpp
#include <algorithm>

reverse(numbers.begin(), numbers.end());
```

### Manual Reverse
```cpp
int leftPointer = 0;
int rightPointer = static_cast<int>(numbers.size()) - 1;
while (leftPointer < rightPointer) {
    swap(numbers[leftPointer++], numbers[rightPointer--]);
}
```

> **Pitfall:** Forgetting to update both pointers (`leftPointer++` and `rightPointer--`).

---

## 3. Common Pitfalls

| Scenario                   | Issue                                    | Recommended Fix                         |
|----------------------------|------------------------------------------|-----------------------------------------|
| Empty array                | Accessing `numbers[0]` is invalid        | Check `numbers.empty()` before access   |
| Off-by-one in loops        | Skipping last element or buffer overrun  | Use `< size()` not `<= size()`          |
| Unsigned index underflow   | Negative index wraps around              | Use signed `int` for indices or validate |
| Modifying container during iteration | Invalidates iterators or skips elements | Use indexed loops or stable iterator logic |

---

## 4. Tips & Best Practices

- **Validate indices** before accessing elements.
- **Leverage STL algorithms** (`std::swap`, `std::reverse`) for clear intent.
- **Use `assert`** in debug builds for safety checks:
  ```cpp
  #include <cassert>
  assert(targetIndex >= 0 && targetIndex < static_cast<int>(numbers.size()));
  ```
- **Descriptive naming**: prefer names like `leftPointer`, `windowSum`, `maxSum` over single letters.


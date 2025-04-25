# Opposing-End Pointers

## What?
This sub-pattern of the two-pointer technique uses **two pointers starting from opposite ends** of a data structure (usually a sorted array) and moving toward each other to solve problems involving comparisons, sums, or maximizing/minimizing values.

## When?
- The array is **sorted** or has an **invariant** that can be exploited.
- You're solving for **a specific pair**, **maximum/minimum**, or **checking conditions** that involve values from both ends.
- Brute-force would be O(N²), but opposing pointers can reduce it to **O(N)**.

## Why?
Opposing pointers allow linear-time traversal **without extra space** and are ideal for problems involving:
- Sums (`pair sum`, `3Sum`)
- Range checks (e.g., find closest values)
- Area or distance calculations (`container with most water`)

## How?

General approach:
```cpp
int left = 0;
int right = static_cast<int>(nums.size()) - 1;

while (left < right) {
    int sum = nums[left] + nums[right];
    
    if (sum == target) {
        // Found a valid pair
    } else if (sum < target) {
        ++left; // Need a larger sum
    } else {
        --right; // Need a smaller sum
    }
}
```
## Common Problems
| Problem                                                    | Idea                                                                                                                         |
|------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------|
| [Container With Most Water](container_with_most_water.cpp) | Move inward while tracking max area formed by two heights.                                                                   |
| [Is Palindrome](is_palindrome.cpp)                      | Compare characters from both ends to check if a string is a palindrome.                                                      |
| [Reverse String](reverse_string.cpp)                       | Swap characters from both ends.                                                                                              |
| [Two Sum (Sorted)](two_sum_sorted.cpp)                     | Find two numbers that add up to a target.                                                                                    |
| [Two Sum (Unsorted)](two_sum_unsorted.cpp)                 | Use a hash map to track seen values. For each number, check if the complement exists.                                        |
| [Trap Rain Water](trap_rain_water.cpp)                     | rack `leftMax` and `rightMax`. At each step, water = min(leftMax, rightMax) - currentHeight. Move pointer on the lower side. |

## Key Takeaways
- **Sorted Input** is oftern required or beneficial.
- Always make sure `left < right` and update both pointers appropriately.
- Involves **one pass**, no need to revisit elements.
- Easy to reason with using **symmetry** or **greedy logic** (e.g., choosing max height from sides).

## Pitfalls
- Not moving the correct pointer (e.g., increasing left when you should decrease right).
- Forgetting `left < right` loop condition.
- Misusing in unsorted input (you'll need hashsets or extra steps instead).

This pattern is a must-have tool for your algorithm toolkit — especially in interviews where linear-time solutions on sorted arrays are gold.

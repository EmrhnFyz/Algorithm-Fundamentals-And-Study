# Sliding Window Pattern

## What?
The **Sliding Window** pattern is used to efficiently process a subset (window) of elements in a linear data structure — usually arrays or strings — without re-evaluating the entire subset on every iteration.

You maintain a "window" (range of indices) and slide it across the input while updating some state (sum, count, frequency, etc.).

## When?
- You're working with **subarrays or substrings**
- The problem asks for the:
  - Maximum/minimum of a window of size `k`
  - Longest/shortest subarray satisfying a condition
  - Count of distinct elements or character frequencies
- You need to improve upon a brute-force **O(n²)** solution

## Why?
Sliding Window helps reduce **nested loops** and achieves **O(n)** or **O(n log k)** time depending on the problem and technique.

## Variations

### 1. Fixed-Size Window
- The window size `k` is known and constant.
- Slide the window from left to right while maintaining the required state.

**Common Use Cases**:
- Max sum of subarray of size `k`
- Average of subarray of size `k`

### 2. Variable-Size Window
- The window size expands/contracts based on a condition.
- Useful for problems with constraints like "at most K distinct characters", or "minimum window with sum ≥ S".

**Common Use Cases**:
- Longest substring with K distinct characters
- Smallest subarray with sum ≥ target

## Common Problems

| Problem                                                                                          | Idea                                                                                           |
|--------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------|
| [Longest Substring with K Distinct](longest_substring_with_k_distinct.cpp)                       | Expand window and track character counts; shrink window when distinct count exceeds K.         |
| [Max Sum of Subarray (Fixed)](max_sum_of_subarray_fixed.cpp)                                     | Maintain a running sum of window size `k`, subtract the element going out and add the new one. |
| [Min Subarray Length ≥ Target (Variable)](min_subarray_length_greater_or__equal_than_target.cpp) | Expand window until it meets condition, then shrink from the left to minimize.                 |

## Time & Space Complexity
- Time: usually **O(n)** — each element enters and exits the window at most once
- Space: O(1) to O(k) depending on state tracking (sum, hash map, frequency array, etc.)

## Pitfalls
- Forgetting to shrink the window properly (esp. variable window)
- Off-by-one errors in window boundaries
- Mismanaging the state update (e.g., not removing an element fully from the frequency map)

This pattern is a must-know for handling **real-time streaming**, **subarray search**, and **efficient string scanning**.

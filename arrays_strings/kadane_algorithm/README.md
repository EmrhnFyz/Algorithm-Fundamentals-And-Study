# Kadane’s Algorithm

## What?
Kadane’s Algorithm is an efficient method to find the **maximum sum of a contiguous subarray** within a one-dimensional array of numbers (can be positive, negative, or zero).

## When?
- You're asked to find the **maximum subarray sum** (classic use case)
- You want to track the best interval in terms of additive value
- Problems like: "Best time to buy/sell", "Max profit", "Max sum of energy", etc.

## Why?
The brute-force solution takes **O(n²)** or worse, checking every subarray.  
Kadane’s reduces this to **O(n)** by making a simple observation:
> “The max subarray ending at index `i` is either the element `nums[i]` itself or `nums[i] + max ending at i - 1`.”

## How?
Kadane’s algorithm builds the solution by scanning the array once and making a simple decision at each index:
1. Start with `currentSum = nums[0]` and `maxSum = nums[0]`.
2. At each position i, decide:
   1. Start a new subarray from `nums[i]`, if `nums[i]` alone is better.
   2. Extend the previous subarray by adding `nums[i]` to the currentSum.
3. Update the `maxSum` if the new `currentSum` is larger than the current best found so far.
4. Continue until the end of the array.
By making a local decision at each step (start fresh or extend), Kadane’s algorithm guarantees the globally maximum subarray sum.

### 📜 Core Template
```cpp
int current = nums[0];
int maxSum = nums[0];

for (int i = 1; i < nums.size(); ++i) 
{
    current = max(nums[i], current + nums[i]);
    maxSum = max(maxSum, current);
}
```

🔁 What's happening?
- You're making a choice at every index:
    - "Should I start a new subarray here?"
    - "Or should I extend the one I've been building?"

## Common Problems
| Problem                                          | Idea                                                                                |
|--------------------------------------------------|-------------------------------------------------------------------------------------|
| [Maximum Subarray Sum](maximum_subarray_sum.cpp) | Use dynamic programming-style logic to track the best subarray ending at each point |

## Time & Space Complexity
⏱ Time: O(n)
🧠 Space: O(1) — constant tracking variables

## Pitfalls
Forgetting to handle all negative arrays (e.g., [-3, -1, -2] -> answer is -1)

Using 0 instead of nums[0] as initialization — this breaks when all elements are negative

Kadane’s is one of the most powerful "greedy + dynamic" hybrids and appears in many real-world problems — a must-have in your algorithm toolbox!
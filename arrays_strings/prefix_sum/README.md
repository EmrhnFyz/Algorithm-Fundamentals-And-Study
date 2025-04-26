# Prefix Sum Pattern

## What?
The **Prefix Sum** technique involves building an auxiliary array where each element at index `i`
stores the sum of all elements from index `0` to `i-1` of the original array.

This allows us to compute **sum of any subarray [i...j] in O(1)** using:

`rangeSum = prefix[j + 1] - prefix[i]`


## When?
- When you're answering **multiple range-sum queries** efficiently
- When the array is **static/immutable** and won't be updated
- When you want to precompute partial aggregates (sums, counts, etc.)

## ⚠️ Immutable vs Mutable Range Sum

| Type      | Can Update Array? | Query Time | Update Time | Tool Needed                 |
|-----------|-------------------|------------|-------------|-----------------------------|
| Immutable | ❌ No              | ✅ O(1)     | ❌ N/A       | Prefix Sum (this pattern)   |
| Mutable   | ✅ Yes             | ✅ O(log n) | ✅ O(log n)  | Segment Tree / Fenwick Tree |

### 🔸 Why prefix sum doesn't work for mutable arrays:
- Prefix sums are **precomputed**, so any update to the array invalidates the entire prefix structure.
- For mutable scenarios, you'll need a dynamic structure like a **Segment Tree** or **Binary Indexed Tree (Fenwick Tree)**.

## Why?
Prefix sum avoids recomputing sums repeatedly. Once precomputed, it lets you:
- Query any subarray sum in **O(1)**
- Count matching patterns across large data ranges efficiently

## How?
Prefix sums work by accumulating values from left to right:
1. Start with a base value (prefix[0] = 0) — representing the sum before any elements.
2. For each element i in the array:
   1. Add it to the cumulative sum from the previous step.
   2. Store this running total in prefix[i + 1].
3. Once the prefix array is built, the sum of any subarray nums[i...j] can be quickly computed as:
   1. prefix[j + 1] - prefix[i]
4. This turns a potentially O(n) subarray sum operation into O(1) after O(n) preprocessing.

### 📦 Prefix Sum Construction

```cpp
vector<int> prefix(nums.size() + 1, 0); // +1 to simplify the math

for (int i = 0; i < nums.size(); ++i) 
{
    prefix[i + 1] = prefix[i] + nums[i];
}
```
Now:
- prefix[3] = sum of nums[0] + nums[1] + nums[2]
- prefix[j + 1] - prefix[i] = sum of subarray nums[i...j]

## Common Problems

| Problem                                                      | 	Idea                                                                               |
|--------------------------------------------------------------|-------------------------------------------------------------------------------------|
| [Range Sum Query	(Immutable)](range_sum_query_immutable.cpp) | prefix array. Any sum(i, j) = prefix[j+1] - prefix[i]                               |
| [Subarray Sum Equals K](subarray_sum_equals_k.cpp)           | 	Use running sum + hash map to count how many previous sums lead to current sum − K |

## Time & Space Complexity

⏱ Prefix construction: O(n)

📦 Querying sum: O(1)

🧠 Space: O(n) for prefix array

## Pitfalls
- Off-by-one errors when querying (use j+1, not j)
- Forgetting to initialize prefix[0] = 0
- Using prefix sum for mutable arrays (not supported)


Prefix Sum makes it easy to answer complex sum-related problems in linear time — it’s a must-have tool in your algorithm toolkit.

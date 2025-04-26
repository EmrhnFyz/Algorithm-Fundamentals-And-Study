# Binary Search Variations

## What?
Binary search is a divide‑and‑conquer technique that finds a target value by repeatedly halving the search space.
It assumes the array or the logical structure being searched is **sorted** (or can be reasoned about as ordered).

Instead of scanning sequentially (O(N)), binary search cuts the search space in half each step — achieving **O(log N)** efficiency.

## When?
Use binary search when:
- The input array or search space is sorted or monotonic (non‑decreasing or non‑increasing).
- You need to efficiently find a target value, boundary condition, or feasibility.
- Problems ask for "minimum/maximum value satisfying a condition" (binary search the answer space).

## Why?
Binary search reduces the time complexity from **O(N)** to **O(log N)** by eliminating half the search space at each decision point.

It is the backbone of many advanced algorithms in dynamic programming, optimization, and graph search techniques.

## How?
Binary search works by dividing the problem into halves at each step:
1. Start with two pointers: `left` at the beginning and `right` at the end of the array.
2. Calculate the middle index `mid`.
   1. Compare `nums[mid]` with the target:
   2. If `nums[mid] == target`, you've found the answer.
   3. If `nums[mid] < target`, search the right half by moving `left = mid + 1`.
   4. If `nums[mid] > target`, search the left half by moving `right = mid - 1`.
3. Repeat until `left > right` (search space exhausted).

By halving the search space each time, binary search guarantees O(log N) time complexity.

### 📜 Core Template
```cpp
int left = 0, right = n - 1;

while (left <= right) 
{
    int mid = left + (right - left) / 2;

    if (nums[mid] == target) 
    {
        return mid;
    } 
    else if (nums[mid] < target) 
    {
        left = mid + 1;
    } 
    else 
    {
        right = mid - 1;
    }
}
```

Modify this template carefully depending on:
- Whether searching for exact match
- Whether finding the lower/upper bound
- Whether searching in a conceptual space (answer space search)

## Common Problems
| Problem                        | Idea                                                                         |
|--------------------------------|------------------------------------------------------------------------------|
| Standard Binary Search         | Classic find target in sorted array                                          |
| Search in Rotated Sorted Array | Adapt binary search to rotated arrays by reasoning about sorted halves       |
| Binary Search on Answer Space  | When elements aren’t sorted, but the range of answers can be binary searched |

## Key Takeaways
- **Base condition**: always ensure left ≤ right, and mid is safely calculated (avoid overflow).
- **Variants**: adapt binary search carefully for finding first occurrence, last occurrence, or boundary values.
- **Answer Space Binary Search**: sometimes we search not the array itself, but the logical "answer space" for feasibility.
- **Pitfalls**: off‑by‑one errors (left, right, mid), infinite loops, misplacing boundary updates.

-Mastering binary search patterns is essential for efficient problem-solving, especially under tight performance constraints.


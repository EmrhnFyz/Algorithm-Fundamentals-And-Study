# Arrays & Strings

## What?
Arrays are contiguous sequences of elements supporting constant‑time indexed access; strings are arrays of characters used for textual data. These structures form the foundation for many algorithmic patterns.

## When?
Use array and string techniques whenever you need to process or query sequences of values in order, perform random-access operations, or handle subarray/substring problems efficiently.

## Why?
They underpin a wide range of algorithms—from two‑pointer and sliding‑window patterns to prefix‑sum techniques and dynamic programming. Mastering these basics lets you optimize from O(N²) brute‑force to O(N) or O(N log N) solutions.

## Subtopics Covered
1. [**Basics & Pitfalls**](basics)
    - Traversal & indexing
    - In-place swapping & reversing
    - Pitfall table: common issues and fixes

2. **Two-Pointer Pattern**
    - Opposing pointers (pair sum, container-with-most-water)
    - Fast/slow pointers (middle‑of‑list, cycle detection)

3. **Sliding-Window Pattern**
    - Fixed-size window (max/min subarray sum of length K)
    - Dynamic window (the smallest subarray ≥ S, the longest substring with K distinct chars)

4. **Prefix-Sum Technique**
    - Build cumulative-sum array for O(1) range-sum queries
    - Subarray-sum equals K using hash-map on prefix values

5. **Kadane’s Algorithm**
    - Maximum contiguous subarray sum in one pass (O(N) time, O(1) space)

## Key Takeaways
- **Indexed access**: Arrays/strings allow O(1) element retrieval but watch for off‑by‑one and out‑of‑bounds errors.
- **Two‑pointer** reduces nested loops by converging from ends or using fast/slow scans.
- **Sliding‑window** transforms repeated subarray aggregation into linear-time updates.
- **Prefix‑sum** trades O(N) preprocessing for O(1) range-sum queries—ideal for frequent queries.
- **Kadane’s** leverages local vs. global maxima to find the best subarray without extra memory.
- **Edge cases**: empty arrays, K > N, all negatives, uniform data—always include boundary checks.


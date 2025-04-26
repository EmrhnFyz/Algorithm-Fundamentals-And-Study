# Comparison-Based Sorting

## What?
Comparison-based sorting algorithms determine the order of elements **by comparing pairs of elements** using "greater than" or "less than" operations.

This includes familiar sorts like **Merge Sort**, **Quick Sort**, and **Heap Sort** — all achieving **O(N log N)** average performance by strategically arranging comparisons.

Unlike counting-based sorts, comparison-based sorts work with **any** type of comparable data — numbers, strings, custom objects, etc.

## When?
Use comparison-based sorting when:
- Elements can only be compared, not bucketed or counted directly (general data types).
- The input size is moderate to large (N > 1000).
- You need stable, general-purpose, or in-place sorting depending on constraints.

Common in problems involving:
- Preprocessing before binary search or grouping
- Sorting complex objects (e.g., by multiple keys)
- Optimizing greedy decisions (sort before greedy selection)

## Why?
Comparison-based sorts offer reliable, consistent performance across **almost all types of input**, regardless of value distribution or range.

They're foundational to:
- Efficient searching
- Data organization
- Preparing input for dynamic programming, greedy, or graph problems

Without them, many optimization strategies become infeasible at scale.

## How?
### 📦 Merge Sort Outline
```cpp
// Pseudocode
if (array has more than 1 element)
{
    split array into two halves
    recursively sort each half
    merge the sorted halves
}
```
- Recursively sorts two halves, then merges them.
- Stable but needs extra space.

### 📜 Merge Sort Walkthrough
- Suppose we have the array:
```cpp
[5, 2, 9, 1, 5, 6]
```
### 1️⃣ Initial Split (Divide Phase)

- Split array into two halves:
```cpp
[5, 2, 9] and [1, 5, 6]
```
- Recursively split each half:

Split `[5, 2, 9]`
```cpp
[5] and [2, 9]
```
Split `[2, 9]`
```cpp
[2] and [9]
```
Split: `[1, 5, 6]`
```cpp
[1] and [5, 6]
```
Split: `[5, 6]`
```cpp
[5] and [6]
```
At the deepest level, all subarrays are size 1 (which are trivially sorted):
```cpp
[5], [2], [9], [1], [5], [6]
```

### 2️⃣ Merging (Conquer and Combine)
Now start merging sorted pieces upward.
- Merge `[2]` and `[9]` → sorted `[2, 9]`
- Merge `[5]` and `[2, 9]` → merge step:

Compare elements:
```cpp
5 vs 2 → 2 goes first
5 vs 9 → 5 goes next
9 remains → 9 goes last
```
Result:
```cpp
[2, 5, 9]
```

- Merge `[5]` and `[6]` → sorted `[5, 6]`
- Merge `[1]` and `[5, 6]` → merge step:

Compare elements:
```cpp
1 vs 5 → 1 goes first
5 vs 6 → 5 goes next
6 remains → 6 goes last
```
Result:
```cpp
[1, 5, 6]
```

### 3️⃣ Final Merge
Merge `[2, 5, 9]` and `[1, 5, 6]`:

Compare elements:
```cpp
2 vs 1 → 1 goes first
2 vs 5 → 2 goes next
5 vs 5 → 5 (from left) goes next (preserve stability)
9 vs 5 → 5 (from right) goes next
9 vs 6 → 6 goes next
9 remains → 9 goes last
```

Final sorted array:
```cpp
[1, 2, 5, 5, 6, 9]
```

### 🧠 Summary Visualization
```cpp
Original: [5, 2, 9, 1, 5, 6]

Split into:
[5, 2, 9]  and  [1, 5, 6]

Split further:
[5], [2, 9]    and    [1], [5, 6]

Split further:
[5], [2], [9], [1], [5], [6]

Start merging:
[2, 9], [5]  → [2, 5, 9]
[5, 6], [1]  → [1, 5, 6]

Merge final:
[2, 5, 9] and [1, 5, 6] → [1, 2, 5, 5, 6, 9]
```

### Key Takeaways
- Merge Sort **splits first, merges later** — don't confuse it with insertion-style thinking.
- At every merge step, two already sorted halves are merged in O(n) time.
- Total time is O(n log n) because there are log n levels of splitting, and each level processes n elements.


---

### 📦 Quick Sort Outline
```cpp
if (array has more than 1 element) 
{
    choose a pivot element
    partition array into elements < pivot and elements > pivot
    recursively sort left and right partitions
}
```
- Divides based on pivot; sorts by in-place swaps.
- Very fast on average but unstable and sensitive to pivot choice.

### 📜 Quick Sort Walkthrough
Suppose we have the array:
```cpp
[5, 2, 9, 1, 5, 6]
```

### 1️⃣ Choose a Pivot (Divide Phase)
Let’s pick the last element as pivot.
In this case:
```cpp
Pivot = 6
```

Goal: Partition the array so that:
- Elements ≤ **pivot** go to the left
- Elements > **pivot** go to the right

### 2️⃣ Partition Around Pivot
Start comparing from left to right:

| i (smaller area index) | j (current checking) | nums[j] | Action                                                             |
|------------------------|----------------------|---------|--------------------------------------------------------------------|
| -1                     | 5                    | 5       | 5 ≤ 6 → increment i (0) and swap nums[i], nums[j] (no real change) |
| 0                      | 2                    | 2       | 2 ≤ 6 → increment i (1) and swap nums[i], nums[j]                  |
| 1                      | 9                    | 9       | 9 > 6 → do nothing                                                 |
| 1                      | 1                    | 1       | 1 ≤ 6 → increment i (2) and swap nums[i], nums[j]                  |
| 2                      | 5                    | 5       | 5 ≤ 6 → increment i (3) and swap nums[i], nums[j]                  |

Result after partition (before placing pivot):

```cpp
[5, 2, 1, 5, 9, 6]
          ↑
         (i=3)
```
Now place pivot (6) at position i+1 (index 4):

Result:
```cpp
[5, 2, 1, 5, 6, 9]
```
Pivot 6 is now at index 4, and the array is split into:

Left: [5, 2, 1, 5] (elements ≤ 6)

Right: [9] (elements > 6)

### 3️⃣ Recursive Sort Left Half [5, 2, 1, 5]
Pivot = last element → 5

Partition [5, 2, 1] around pivot 5:

Partition steps:

| i  | j | nums[j] | Action                               |
|----|---|---------|--------------------------------------|
| -1 | 5 | 5       | 5 ≤ 5 → i = 0, swap (no real change) |
| 0  | 2 | 2       | 2 ≤ 5 → i = 1, swap                  |
| 1  | 1 | 1       | 1 ≤ 5 → i = 2, swap                  |

Result:
```cpp
[5, 2, 1, 5]
           ↑
          (i=2)
```

Now place pivot 5 at i+1 (index 3).

Array remains:
```cpp
[5, 2, 1, 5]
```
(Already partitioned correctly.)

### 4️⃣ Recursive Sort [5, 2, 1]

recursively sort [5, 2, 1]:

Pivot = 1

Partition:

| i  | j | nums[j] | Action          |
|----|---|---------|-----------------|
| -1 | 5 | 5       | 5 > 1 → no move |
| -1 | 2 | 2       | 2 > 1 → no move |

No smaller elements.
Swap pivot 1 with nums[i+1] = nums[0]:

Result:

```cpp
[1, 2, 5]
```

### 5️⃣ Now All Pieces Sorted
The array becomes:
```cpp
[1, 2, 5, 5, 6, 9]
```
Sorted!

### 🧠 Quick Sort Key Points Summary

- Choose a pivot (commonly last element)
- Partition array into ≤ pivot (left) and > pivot (right)
- Recursively sort both sides
- No extra memory needed (in-place)
- Pivot selection matters: bad pivot can cause O(n²) time

---

### 📦 Heap Sort Outline

```cpp
build a max heap from the array
for (each element from end to start) 
{
    swap the root (max) with the last element
    reduce heap size
    heapify the root to maintain max heap property
}
```
- Uses a heap data structure.
- Guarantees O(N log N) performance and works in-place, but not stable.

### 📜 Heap Sort Walkthrough
Suppose we have the array:
```cpp
[5, 2, 9, 1, 5, 6]
```
### 1️⃣ Step 1: Build a Max Heap
Build a max-heap from the array:
(Parent node must be larger than both child nodes.)

We start **heapifying from the last non-leaf node:**
- Last non-leaf node = index (n/2 - 1) = 6/2 - 1 = 2
Heapify from index 2:
- Node = `9` (already bigger than its children, no change).
Heapify from index 1:
- Node = `2`
- Children = `1` (left), `5` (right)
- Largest child is `5`.
- Swap `2` and `5`.

Array becomes:
```cpp
[5, 5, 9, 1, 2, 6]
```

Heapify from index 0:
- Node = `5`
- Children = `5` (left), `9` (right)
- Largest child is `9`.
- Swap `5` and `9`.

Array becomes:
```cpp
[9, 5, 5, 1, 2, 6]
```

✅ Now we have a Max Heap:
```cpp
    9
  /   \
 5     5
/ \   /
1  2 6
```

### 2️⃣ Step 2: Sorting by Extracting Max Elements

Now start swapping the root with the last unsorted element, and heapify again:

First Extraction:
Swap root `9` with last element `6`.

Array becomes:
```cpp
[6, 5, 5, 1, 2, 9]
```
(Sorted part: `[9]`)
Heapify root (index 0, size 5):
- Node = `6`
- Children = `5` (left), `5` (right)
- 6 already bigger, no swap needed.

✅ Heap after heapify:
```cpp
     6
   /   \
  5     5
 / \
1   2
```

Second Extraction:
Swap root `6` with last unsorted element `2`.

Array becomes:
```cpp
[2, 5, 5, 1, 6, 9]
```
(Sorted part: `[6, 9]`)
Heapify root (index 0, size 4):
- Node = `2`
- Children = `5` (left), `5` (right)
- Largest child = `5`
- Swap `2` and `5`.

Array becomes:
```cpp
[5, 2, 5, 1, 6, 9]
```
Heapify index 1:
- Node = `2`
- Left child = `1`
- No swap needed.

✅ Heap after heapify:

```cpp
     5
   /   \
  2     5
 /
1
```

Third Extraction:
Swap root `5` with last unsorted element `1`.

Array becomes:
```cpp
[1, 2, 5, 5, 6, 9]
```

(Sorted part: `[5, 6, 9]`)
Heapify root (index 0, size 3):
- Node = `1`
- Children = `2` (left), `5` (right)
- Largest child = `5`
- Swap `1` and `5`.

Array becomes:
```cpp
[5, 2, 1, 5, 6, 9]
```

✅ Heap after heapify:
```cpp
   5
 /   \
2     1
```

Fourth Extraction:
Swap root `5` with last unsorted element `1`.

Array becomes:
```cpp
[1, 2, 5, 5, 6, 9]
```
(Sorted part: `[5, 5, 6, 9]`)

Heapify root (index 0, size 2):
- Node = `1`
- Left child = `2`
- Swap `1` and `2`.

Array becomes:
```cpp
[2, 1, 5, 5, 6, 9]
```
✅ Heap after heapify:
```cpp
  2
 /
1
```

Fifth Extraction:
Swap root `2` with last unsorted element `1`.

Array becomes:
```cpp
[1, 2, 5, 5, 6, 9]
```
(Sorted part: `[2, 5, 5, 6, 9]`)

Only one element left — array is now sorted.

✅ Final sorted array:
```cpp
[1, 2, 5, 5, 6, 9]
```
### 🧠 Heap Sort Key Points Summary
- Build a max heap once (O(n))
- Repeatedly swap the root with the last element and heapify (O(log n) per element)
- Total Time Complexity = O(n log n)
- Heap Sort is in-place but not stable

### 📜 Full Timeline (Shortened)
```cpp
Build Max Heap → [9, 5, 5, 1, 2, 6]

Extract 9 → [6, 5, 5, 1, 2, 9]
Extract 6 → [2, 5, 5, 1, 6, 9]
Extract 5 → [1, 2, 5, 5, 6, 9]
Extract 5 → [2, 1, 5, 5, 6, 9]
Extract 2 → [1, 2, 5, 5, 6, 9]

Sorted: [1, 2, 5, 5, 6, 9]
```

---

## Subtopics Covered
- [**Merge Sort**](merge_sort.cpp) — Stable sort, divides and merges recursively.
- [**Quick Sort**](quick_sort.cpp) — Partition-based sort, fast in practice but unstable.
- [**Heap Sort**](heap_sort.cpp) — In-place, comparison-based, uses heap structure to maintain order.


Key Takeaways
- **O(N log N)** runtime is the best achievable by any comparison-based sort (proven lower bound).
- **Merge Sort** is stable (preserves equal elements' order) but needs extra memory.
- **Quick Sort** is in-place and usually fastest in practice, but has worst-case O(N²) if pivots are poor.
- **Heap Sort** guarantees O(N log N) worst-case time and is memory-efficient but not stable.
- Choose your sorting algorithm based on needs: stability, memory usage, average vs worst-case performance.

Comparison-based sorting is a fundamental pillar of efficient algorithm design.



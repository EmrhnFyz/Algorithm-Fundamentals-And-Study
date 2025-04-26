# Counting-Based Sorting

## What?
Counting-based sorting algorithms are non-comparison sorts that **do not compare elements against each other**.  
Instead, they **count occurrences** or **group elements by their digits or values** to achieve sorting.

They can achieve **O(N)** linear time under the right conditions — bypassing the O(N log N) lower bound for comparison-based sorts.

Examples include **Counting Sort** and **Radix Sort**.

## When?
Use counting-based sorts when:
- Input elements are integers or can be **mapped to integers** easily (e.g., small range of discrete values).
- The range of input values (max - min) is not excessively large.
- Stability is important (Radix Sort is stable).
- You need faster-than-O(N log N) sorting for large datasets with restricted value ranges.

Common in problems involving:
- Frequency counts
- Bucketing elements
- Sorting IDs, ages, scores, small bounded integers

## Why?
When the data fits the right constraints:
- Counting Sort can sort **n elements in O(n + k)**, where `k` is the range of input values.
- Radix Sort can sort **large numbers** by processing one digit at a time, still achieving near-linear performance.

They are crucial tools for **linear-time preprocessing** before applying further algorithms (like greedy, DP, graph problems).

## How?

While different in mechanics, most counting-based sorts share the idea of **indirect placement without comparisons**.

### 📦 Counting Sort Outline

```cpp
count frequency of each value
accumulate frequencies to find positions
place each element into its correct position
```

- Best for small integer ranges (e.g., 0-1000).
- Extra memory proportional to the range of values.

### 📜 Counting Sort Walkthrough
Suppose we have the array:

```cpp
[5, 2, 9, 1, 5, 6]
```

### 1️⃣ Step 1: Find Maximum Value
We scan the array to find the maximum value.
This tells us the size of the count array.

Here:
```cpp
max = 9
```

### 2️⃣ Step 2: Create and Fill the Count Array
We create a count array of size (max + 1), initialized with all zeros:

```cpp
Index:  0 1 2 3 4 5 6 7 8 9
Count: [0 0 0 0 0 0 0 0 0 0]
```

Now we count the frequency of each number by iterating through the input array:

Processing input `[5, 2, 9, 1, 5, 6]`:

| Current Number | Action                        | Updated Count Array   |
|----------------|-------------------------------|-----------------------|
| 5              | Increment count[5] by 1       | [0 0 0 0 0 1 0 0 0 0] |
| 2              | Increment count[2] by 1       | [0 0 1 0 0 1 0 0 0 0] |
| 9              | Increment count[9] by 1       | [0 0 1 0 0 1 0 0 0 1] |
| 1              | Increment count[1] by 1       | [0 1 1 0 0 1 0 0 0 1] |
| 5              | Increment count[5] by 1 again | [0 1 1 0 0 2 0 0 0 1] |
| 6              | Increment count[6] by 1       | [0 1 1 0 0 2 1 0 0 1] |


✅ Final count array:

```cpp
Index:  0 1 2 3 4 5 6 7 8 9
Count: [0 1 1 0 0 2 1 0 0 1]
```

### 3️⃣ Step 3: Rebuild the Sorted Array

Now, reconstruct the sorted array:

Traverse count array from 0 to max.

For each index, if count > 0, put that value into the original array count times.

| Index | Count | Action     | Sorted Array (in-progress) |
|-------|-------|------------|----------------------------|
| 0     | 0     | skip       |                            |
| 1     | 1     | add one 1  | [1]                        |
| 2     | 1     | add one 2  | [1, 2]                     |
| 3     | 0     | skip       | [1, 2]                     |
| 4     | 0     | skip       | [1, 2]                     |
| 5     | 2     | add two 5s | [1, 2, 5, 5]               |
| 6     | 1     | add one 6  | [1, 2, 5, 5, 6]            |
| 7     | 0     | skip       | [1, 2, 5, 5, 6]            |
| 8     | 0     | skip       | [1, 2, 5, 5, 6]            |
| 9     | 1     | add one 9  | [1, 2, 5, 5, 6, 9]         |

✅ Final sorted array:

```cpp
[1, 2, 5, 5, 6, 9]
```

### 🧠 Counting Sort Key Points Summary
- Use count array to store how many times each value appears.
- No comparisons between elements are made.
- Reconstruct the sorted array by **filling from count array**.
- Time Complexity: O(n + k) where `n` = number of elements, `k` = range of numbers.
- Space Complexity: O(k) extra space for count array.
- Very fast when `k` (the range) is small compared to `n`.



### 📦 Radix Sort Outline

```cpp
for each digit place (least to most significant):
    use stable sort (e.g., counting sort) to sort elements by current digit
```

- Best for sorting large integers (e.g., 32-bit IDs, long numbers).
- Relies on digit-by-digit grouping and stability.
- Can be O(N × log(MaxValue)) or O(N × NumberOfDigits).

### 📜 Radix Sort Walkthrough
Suppose we have the array:

```cpp
[170, 45, 75, 90, 802, 24, 2, 66]
```

### 1️⃣ Step 1: Find Maximum Value
First, find the maximum number to determine how many digits we need to process.

Maximum value:
```cpp
802
```
- It has 3 digits → we need to sort units, tens, and hundreds places.

### 2️⃣ Step 2: Sort by Each Digit Place
We sort numbers digit by digit, starting from the 1’s place, then 10’s place, then 100’s place.

We use Counting Sort at each digit place to stably group numbers.

🔹 Pass 1: Sort by 1’s place (units digit)
Extract digits at the 1's place:


| Number | 1's Digit |
|--------|-----------|
| 170    | 0         |
| 45     | 5         |
| 75     | 5         |
| 90     | 0         |
| 802    | 2         |
| 24     | 4         |
| 2      | 2         |
| 66     | 6         |

Sort by 1’s digit:
```cpp
[170, 90, 802, 2, 24, 45, 75, 66]
```

✅ Array after sorting by 1’s place:
```cpp
[170, 90, 802, 2, 24, 45, 75, 66]
```

🔹 Pass 2: Sort by 10’s place (tens digit)
Extract digits at the 10's place:

| Number | 10's Digit |
|--------|------------|
| 170    | 7          |
| 90     | 9          |
| 802    | 0          |
| 2      | 0          |
| 24     | 2          |
| 45     | 4          |
| 75     | 7          |
| 66     | 6          |

Sort by 10’s digit:
```cpp
[802, 2, 24, 45, 66, 170, 75, 90]
```

✅ Array after sorting by 10’s place:
```cpp
[802, 2, 24, 45, 66, 170, 75, 90]
```

🔹 Pass 3: Sort by 100’s place (hundreds digit)
Extract digits at the 100's place:

| Number | 100's Digit |
|--------|-------------|
| 802    | 8           |
| 2      | 0           |
| 24     | 0           |
| 45     | 0           |
| 66     | 0           |
| 170    | 1           |
| 75     | 0           |
| 90     | 0           |

Sort by 100’s digit:
```cpp
[2, 24, 45, 66, 75, 90, 170, 802]
```

✅ Array after sorting by 100’s place:
```cpp
[2, 24, 45, 66, 75, 90, 170, 802]
```

### 🧠 Radix Sort Key Points Summary
- Sort by least significant digit first.
- Each pass must use a stable sort (e.g., Counting Sort).
- After processing all digit places, the array is fully sorted.
- No comparisons between full numbers — only digits!
- Time Complexity: O(d × (n + k)) where d = number of digits.

### 📜 Full Timeline
```.md
Original array: [170, 45, 75, 90, 802, 24, 2, 66]

→ After 1's place sort: [170, 90, 802, 2, 24, 45, 75, 66]
→ After 10's place sort: [802, 2, 24, 45, 66, 170, 75, 90]
→ After 100's place sort: [2, 24, 45, 66, 75, 90, 170, 802]

Final sorted array: [2, 24, 45, 66, 75, 90, 170, 802]
```



### Subtopics Covered
- [**Counting Sort**](counting_sort.cpp) — Direct counting by value frequency.
- [**Radix Sort**](radix_sort.cpp) — Sorting numbers digit by digit using stable sorting.

### Key Takeaways
- Counting Sort is extremely fast when input values are small and bounded but requires extra memory.
- Radix Sort extends counting ideas to multi-digit numbers while maintaining linear-like performance.
- Both techniques bypass comparison limits — achieving faster-than-O(N log N) sorting when applicable.
- Careful about memory use: Counting Sort can become inefficient if the value range is too large.

Counting-based sorting algorithms are indispensable for high-efficiency processing when the data type and range allow.
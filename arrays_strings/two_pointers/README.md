# Two-Pointer Pattern

## What?
The two-pointer pattern uses two indices (pointers) that traverse a data structure—typically an array or list—in coordinated fashion to solve problems in linear time. 
One pointer often moves from the start while the other moves from the end (or at a different speed), maintaining invariants that let you avoid nested loops.


## When?
- **Sorted arrays**: finding pairs with a given sum or closest sum.
- **Unsorted arrays/lists**: detecting cycles (fast/slow pointers) or finding the middle element.
- **Problems requiring a pair or window scan** where a brute-force O(N²) would be too slow but you can exploit order or two-phase scanning.

## Why?
Two pointers reduce many quadratic-time approaches down to **O(N)** by moving pointers inward (or at different rates) based on comparisons or conditions, thus visiting each element at most once per pointer.

## Common Variations

### 1. Opposite-Ends Pointers
- **Use case**: find two numbers in a sorted array that sum to a target; maximize/minimize functions (e.g., container with most water).
- **Approach**:
  1. Initialize `leftPointer = 0`, `rightPointer = size-1`.
  2. While `leftPointer < rightPointer`:
     - Compute `currentSum = numbers[leftPointer] + numbers[rightPointer]`.
     - If `currentSum == target`, record or return the pair.
     - If `currentSum < target`, increment `leftPointer` to increase sum.
     - Else decrement `rightPointer` to decrease sum.

```cpp
int leftPointer = 0;
int rightPointer = static_cast<int>(numbers.size()) - 1;
while (leftPointer < rightPointer) {
    int sum = numbers[leftPointer] + numbers[rightPointer];
    if (sum == target) {
        // found a pair
    } else if (sum < target) {
        ++leftPointer;
    } else {
        --rightPointer;
    }
}
```

### 2. Fast/Slow Pointers (Tortoise & Hare)
- **Use case**: detect cycles in a linked list; find middle node.
- **Approach**:
  1. Initialize `slow = head`, `fast = head`.
  2. While `fast` and `fast->next` are not null:
     - Move `slow = slow->next`.
     - Move `fast = fast->next->next`.
  3. If using for cycle detection, check if `slow == fast`.
  4. For middle node, when `fast` reaches end, `slow` is at middle.

```cpp
ListNode* slow = head;
ListNode* fast = head;
while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
}
// slow is now middle of list
```

## Key Takeaways
- **Time Complexity**: O(N) — each pointer moves at most N steps.
- **Space Complexity**: O(1) — only two extra pointers or indices.
- **Requirements**: opposite-ends variant often requires sorted data; fast/slow works on linked structures without random access.
- **Pitfalls**:
  - Off-by-one errors if pointers cross incorrectly.
  - Ensure termination conditions avoid infinite loops (especially in fast/slow cycles).
  - Watch for integer overflow when computing midpoints or sum (use `long long` if needed).

Armed with these variations, you can solve a wide range of array, string, and linked-list problems efficiently using the two-pointer pattern.
# Fast & Slow Pointers (Tortoise and Hare)

## What?
The fast & slow pointer technique involves two pointers moving at different speeds through a data structure — typically a **linked list** or **array**. It helps detect patterns like cycles or find positions like the middle node efficiently.

## When?
- Detecting **cycles** in a linked list or array (Floyd's Cycle Detection)
- Finding the **middle** of a linked list in a single pass
- Locating the **start of a cycle**
- Checking if a number is a **happy number** (based on digit square sums)
- Problems involving **looping behavior** or **relative traversal**

## Why?
Fast & slow pointers reduce the need for extra space like hash sets or arrays. They can often replace brute-force or recursive solutions with **O(n)** time and **O(1)** space.

## How?
Fast & slow pointers involve two pointers moving through the data structure at different speeds:

1. **Initialization**: Start both `slow` and `fast` pointers at the beginning (e.g., `head` of a linked list).
2. **Movement**:
    1. `slow` moves forward **one step at a time**.
    2. `fast` moves forward **two steps at a time**.
3. **Detection**:
    1. If the data structure has a **cycle**, the fast pointer will eventually "lap" the slow pointer, and they will meet.
    2. If there is **no cycle**, the fast pointer will eventually reach the end (`nullptr`).
4. **Finding the Middle**:
    1. In a non-cyclic structure (like a normal linked list), when `fast` reaches the end, `slow` will be positioned at the middle node.

This method ensures **O(n)** time and **O(1)** space, with no need for extra data structures.
### 🐢🐇 Classic Pattern

```cpp
ListNode* slow = head;
ListNode* fast = head;

while (fast && fast->next) 
{
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast) 
    {
        // Cycle detected
    }
}
```

## 🧠 Key Insights

- If a cycle exists, the fast pointer will eventually lap the slow one (like runners on a track).
- If no cycle exists, the fast pointer will hit `nullptr` first.
- For middle-finding: when `fast` reaches end, `slow` will be at the midpoint.

## Common Problems

| Problem                                                        | Idea                                                                                                                            |
|----------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------|
| [Detect Cycle in Linked List](detect_cycle_in_linked_list.cpp) | If slow and fast ever meet, a cycle exists.                                                                                     |
| [Find Cycle Start](find_cycle_start.cpp)                       | After detecting a cycle, move one pointer to head and advance both one step at a time until they meet again — that’s the start. |
| [Find Middle of Linked List](find_middle_of_linked_list.cpp)   | Move slow by 1 step, fast by 2 steps. When fast hits the end, slow is at the middle.                                            |

## Time & Space Complexity
- ⏱ Time: O(n) — each node is visited at most twice
- 🧠 Space: O(1) — no extra memory (except pointers)

## Pitfalls
- Forgetting to check `fast && fast→next` before accessing `fast→next→next`
- Misplacing the meeting condition
- Infinite loops if the exit condition isn't properly written

The fast-slow pattern is a must-have in your algorithm toolbox, especially for linked list and cyclic problems.

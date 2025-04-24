# Common Pitfalls Table

A concise reference of common array/string pitfalls, their symptoms, and recommended fixes:

| Scenario                             | Symptom / Issue                          | Recommended Fix                                 |
|--------------------------------------|------------------------------------------|-------------------------------------------------|
| **Empty container**                  | Accessing `numbers[0]` causes UB/crash    | Always check `numbers.empty()` before access    |
| **Off-by-one in loops**              | Skipping last element or overrunning buffer | Use `< size()` instead of `<= size()`           |
| **Unsigned index underflow**         | Negative index wraps to huge positive     | Use signed `int` for indices or validate ≥ 0    |
| **Modifying during iteration**       | Iterator invalidation or skipped elements | Use indexed loops or carefully manage iterators |
| **Mixing signed/unsigned**           | Warnings or unexpected comparisons        | Consistently use signed types for indices       |
| **Magic numbers**                    | Hard-to-read code, brittle behavior       | Use named constants or descriptive variables    |
| **Ignoring assertions**              | Silent failures in production builds      | Add `assert()` checks in debug builds           |
| **Reusing loop variables outside scope** | Confusing values, logic bugs             | Declare loop variables in minimal scope         |
| **Assuming contiguous memory**       | Mistaken pointer arithmetic on non-vector  | Validate that the container supports random access |

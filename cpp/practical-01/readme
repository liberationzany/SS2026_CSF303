## Problem 1 – Dynamic Array Basics
![dynamic array basics](./asssets/dynamicArrayBasic.png)

- **Problem summary:** Read N integers, store them in a dynamic container (vector), then output the maximum, minimum, and sum.
- **Algorithm:** Use `std::vector` to store the numbers, then use STL algorithms `max_element` and `min_element`, and a simple loop for sum.
- **Time complexity:** O(N)
- **Space complexity:** O(N)
- **Reflection:** This problem reinforces basic vector operations and the use of STL algorithms for common tasks.

---

## Problem 2 – Reverse the Array
![reverse array](./asssets/reverseArray.png)

- **Problem summary:** Given N integers, print them in reverse order.
- **Algorithm:** Store in a vector and traverse from last index to first.
- **Time complexity:** O(N)
- **Space complexity:** O(N)
- **Reflection:** Simple reverse traversal demonstrates index manipulation with vectors.

---

## Problem 3 – Remove Duplicates

![remove duplicates](./asssets/removeDuplicate.png)

- **Problem summary:** Remove duplicate values from a list of integers and print the unique values.
- **Algorithm:** Sort the vector, then use `std::unique` to shift duplicates to the end and erase them.
- **Time complexity:** O(N log N) due to sorting
- **Space complexity:** O(N)
- **Reflection:** Learned the combination of sort and unique for deduplication.

---

## Problem 4 – Sliding Window Maximum

![sliding window maximum](./asssets/slidingWindow.png)

- **Problem summary:** For every contiguous subarray (window) of size K, print the maximum element.
- **Algorithm:** Use a deque that stores indices of potential maximums. Maintain decreasing order of values so the front always holds the maximum of the current window.
- **Time complexity:** O(N) – each element is pushed and popped at most once.
- **Space complexity:** O(K) for the deque.
- **Reflection:** This problem illustrates the power of a deque for sliding window problems, reducing complexity from O(NK) to O(N).

---

## Problem 5 – Balanced Line Problem

![balanced line](./asssets/balancedLine.png)

- **Problem summary:** Simulate a line (deque) with push/pop at both ends; after each operation print the current line.
- **Algorithm:** Use `std::deque` to support O(1) operations at both ends. Process each command accordingly.
- **Time complexity:** O(Q) total, each operation O(1)
- **Space complexity:** O(number of elements in line)
- **Reflection:** Direct application of deque operations; good for understanding double-ended queues.

---

## Problem 6 – K Largest Elements

![K largest elements](./asssets/kLargest.png)

- **Problem summary:** Given N numbers, print the K largest numbers in descending order.
- **Algorithm:** Push all numbers into a max heap, then pop K times.
- **Time complexity:** O(N log N) for building heap and popping K times.
- **Space complexity:** O(N)
- **Reflection:** Priority queues are ideal for extracting largest/smallest elements efficiently.

---

## Problem 7 – Running Median

![Running Median](./asssets/runningMedian.png)

- **Problem summary:** After reading each number, output the current median (with one decimal place).
- **Algorithm:** Maintain two heaps: a max heap for the lower half and a min heap for the upper half. Keep them balanced so that the median is either the top of the max heap or the average of both tops.
- **Time complexity:** O(log n) per insertion.
- **Space complexity:** O(n)
- **Reflection:** This classic problem shows how two heaps can efficiently track the median in a stream.

---

## Problem 8 – Subset Generation

![subset generation](./asssets/subset.png)

- **Problem summary:** Print all non‑empty subsets of a given set of N numbers.
- **Algorithm:** Use bitmasking from 1 to (2^N – 1). For each mask, include elements whose bit is set.
- **Time complexity:** O(N * 2^N)
- **Space complexity:** O(N)
- **Reflection:** Bitmasking is a compact way to enumerate subsets, useful when N is small.

---

## Problem 9 – Count Subsets with Even Sum

![even sum subsets](./asssets/countsubsets.png)

- **Problem summary:** Count how many subsets (including empty) have an even sum.
- **Algorithm:** Iterate over all subsets via bitmask, compute sum, check parity.
- **Time complexity:** O(N * 2^N)
- **Space complexity:** O(N)
- **Reflection:** Simple exhaustive enumeration; reinforces bitmask usage and subset generation.

---

## Problem 10 – Count Subsets with Sum Equal to Target

![subset sum target](./asssets/subsetSumTarget.png)

- **Problem summary:** Given a set of numbers and a target sum, count the subsets that sum exactly to target.
- **Algorithm:** Bitmask enumeration over all subsets, summing and comparing.
- **Time complexity:** O(N * 2^N)
- **Space complexity:** O(N)
- **Reflection:** Useful for small N; for larger N a DP approach would be needed, but bitmasking is straightforward for learning.

---


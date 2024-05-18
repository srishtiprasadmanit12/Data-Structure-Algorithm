# Sliding window Technique
The sliding window technique is a powerful approach for solving problems that involve working with a subset of contiguous element in a data structure like an array of a string.This technique helps in reducing the time complexity from O(n^2) to O(n) in many scenarios by avoiding redundant computation.

The sliding window technique involves maintaining a window(subset) of elements that **slides** over the data structure from one end to other to capture different subset. The size of window can be fixed or variable depending on different problem requirement.

Types of Sliding window
1. Fixed size sliding window : window size is constant throughout the process
2. Variable size sliding window : window size can change based on certain consditions or constraints

## Fixed sized sliding window
Purpose:
The fixed-size sliding window technique is used to solve problems that involve processing all contiguous subarrays (or substrings) of a given size k efficiently.

##### Components:

1. Two Pointers:
    * Left Pointer (left): Marks the start of the current window.
    * Right Pointer (right): Marks the end of the current window.
2. Data Structure:
* Typically, this is an array or list that holds the elements of the current window, but often the window's properties (like sum or max) are tracked directly.

##### Steps:

1. **Initialization**:

Calculate the sum (or other property) of the initial window (first k elements).
Initialize the left and right pointers.

2. **Sliding the Window**:

* Move the window one element to the right by:
    * Adding the new element at right pointer to the current window sum.
    * Subtracting the element at the left pointer from the current window sum.
* Update the left pointer to left + 1.
* Update the desired result (e.g., maximum sum) if the current window's property is better.



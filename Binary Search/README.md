# Binary Search
The whole idea of binary search is to reduce the search space by half in each iteration. We keep two variables low and high, which indicate the current search space (i.e. the range of indices where our target element might lie).

The initial search space is 0 to n-1 because any of those indexes can have the target element.

Now, in each iteration, we calculate mid = (low + high)/2.

Case 1: The element at mid (i.e. nums[mid]) is equal to target. In this case, we just return mid.

Case 2: If the element at mid is lower than target then isn't it obvious that the target exists to the right of mid ? Why? Because the array is sorted so all greater elements are towards the right. In this case, we arrange low to be mid + 1.

Case 3: Similar is the case when element at mid is greater than target. We must go left since smaller elements exist to left. So, we change high to mid - 1

We now know when to go left and when to go right. But, till when? Is there any criteria for termination? Yes.

The condition is:

while (low <= high) // This ensures that there is atleast one element in search space

**One more important caution. To find mid, we use mid = low + (high - low)/2 to prevent overflow.**

First occurence of target number 
move right pointer to left until we get leftmost value 

last occurence of target number 
move left pointer to right until we get rightmost value

I find this question a good one , where we find 1st & last occurence both in a single question my making function.
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/ 


## std::lower_bound AND std::upper_bound

**std::lower_bound** :  Finds the first position in the range where an element can be inserted without violating the order. It returns an iterator pointing to the first element that is not less than (i.e., greater than or equal to) the given value.

**std::upper_bound** : Finds the last position in the range where an element can be inserted without violating the order. It returns an iterator pointing to the first element that is greater than the given value.

**Observation : 1** Use while (start <= end) when you need to search for a specific element and ensure all possible elements (including boundaries) are checked.

**Observation : 2** Use while (start < end) when you are shrinking the search space toward a single valid answer (like finding a boundary or position) and want to avoid redundant checks.
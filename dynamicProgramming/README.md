Patterns of questions in dynamic programming 

1. Minimum (Maximum) Path to Reach a Target

   Found this on leetcode, the list of problem https://leetcode.com/problem-list/55ac4kuc/ 

   Brute force approach : finding min/max path among all possible paths before the current state, then add value for the current state.

   we use recursion for this & sometime solution set will be given to us in question itself.
   For example : minCostClimbStairs , minPathSum

   routes[i] = min(routes[i-1], routes[i-2], ... , routes[i-k]) + cost[i]
2. Distinct Ways
3. Merging Intervals
4. DP on Strings
5. Decision Making


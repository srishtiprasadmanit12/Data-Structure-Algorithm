Patterns of questions in dynamic programming 

1. Minimum (Maximum) Path to Reach a Target

   Found this on leetcode, the list of problem https://leetcode.com/problem-list/55ac4kuc/ 

   Brute force approach : finding min/max path among all possible paths before the current state, then add value for the current state.

   we use recursion for this & sometime solution set will be given to us in question itself.
   For example : minCostClimbStairs , minPathSum,minFallingPathSum,coinChange 

   routes[i] = min(routes[i-1], routes[i-2], ... , routes[i-k]) + cost[i]
2. Distinct Ways
   Problem List: https://leetcode.com/list/55ajm50i

   **Statement**
      Given a target find a number of distinct ways to reach the target.
   
   For example: uniquePath , target sum,
3. Merging Intervals
   Problem List: https://leetcode.com/list/55aj8s16

   **Problem Statement**
   
   Given a set of numbers find an optimal solution for a problem considering the current number and the best you can get from the left and right sides.

   **Approach**
   Find all optimal solutions for every interval and return the best possible answer.

   For example:   Unique binary Search Trees 
   
4. DP on Strings
5. Decision Making


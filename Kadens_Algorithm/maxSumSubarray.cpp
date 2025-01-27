//Naive approach
/*
Input: arr[] = {2, 3, -8, 7, -1, 2, 3}
Output: 11
Explanation: The subarray {7, -1, 2, 3} has the largest sum 11.

nested for-loop to find all subarrays and calculate the sum of each subarray.
first loop runs from 0 to n-1 (starting element of subArray) and the second loop runs from i to n-1 (ending element of subArray).

*/


optimized approach -> Kadane's Algorithm

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = nums[0];
        int res = nums[0];
        int n = nums.size();
        for(int i=1;i<n;i++){
            curr = max(curr+nums[i], nums[i]);// this is diffrent & imp step of kaden's algo
            res = max(res,curr);
        }
        return res;
    }
};
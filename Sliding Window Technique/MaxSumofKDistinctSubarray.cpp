/*
We maintain a window size of k and keep track of distinct elements in map and 
for every window size we update maximum sum if all number is distinct in that 
subarray of size k
*/
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
      int n = nums.size();
      unordered_map<int,int>mp; // to maintain window of size k

      long long sum=0,maxSum=0;
      // Calculate sum of first k elements & store numbers it in map,
      // First window
      for(int i=0;i<k;i++){
        sum+=nums[i];
        mp[nums[i]]++; // maintaining frequency of elements
      }

      // Check if the first window is validif size of map is k then, all numbers were distinct,hence calculate maxSum
      if(mp.size()==k){
        maxSum=max(maxSum,sum);
      }

      for(int i=k;i<n;i++){
        mp[nums[i-k]]--; //remove 1st element of array i.e. reduce freq in map

        // Remove it from the map if its count is zero
        if(mp[nums[i-k]]==0){
            mp.erase(nums[i-k]);
        }
        sum = sum-nums[i-k]; //remove leftmost element from sum

        sum=sum+nums[i]; //add right element
        mp[nums[i]]++; //insert this number in map

         //since, we've inserted new element check for max sum
        if(mp.size()==k){
            maxSum = max(maxSum,sum);
        }
      }
    return maxSum;
    }
};

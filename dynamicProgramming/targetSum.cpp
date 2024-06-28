//RECURSION

class Solution {
public:
    int ways(int length,vector<int>&nums,int target,int idx){
        if(idx==length){
            if(target==0) 
                return 1;
            else
                return 0;
        }
        return ways(length,nums,target-nums[idx],idx+1) + ways(length,nums,target+nums[idx],idx+1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n =nums.size();

        return ways(n,nums,target,0);
    }
};

//MEMOISATION 
//2d vector as target & index both are variable

class Solution {
public:
    bool findSubset(int target,vector<int>&nums,int idx,vector<vector<int>>&dp){
        
        if(target==0)  //target achieved
            return true;
        if(target<0 || idx<0) //edge case
            return false;
        if(idx==0){
            return nums[0]==target; //base case
        }
        if(dp[idx][target]!=-1){ 
            return dp[idx][target]; //returning computed value
        }

        bool exclude = findSubset(target,nums,idx-1,dp);
        bool include = false;
        if(target>=nums[idx]) // boundary check 
             include = findSubset(target-nums[idx],nums,idx-1,dp);
        
        //return ans by any way we get
        return dp[idx][target]=include || exclude;
    }
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0)
            return false;

        int target = sum/2;
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return findSubset(target,nums,n-1,dp);
    }
};
        
    
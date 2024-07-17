class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int>res;
        int sum=0;
        int left = 0;
        int n =nums.size();
        int minLen=INT_MAX;
        int len=0;
        for(int right=0;right<n;right++){ 
            sum+=nums[right];
            while(sum>=target){
                len = right-left+1;
                minLen=min(minLen,len);
                sum-=nums[left];
                left++;
            }            
        }
        return minLen==INT_MAX?0:minLen;
    }
};
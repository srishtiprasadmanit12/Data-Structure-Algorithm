class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left=0,maxLen=0,zeros=0; // ( 1,1,0,1 )
        int n = nums.size();
        //handling edge case of all element as 0 or 1 of array nums
        int cnt_zero=0,cnt_one=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) cnt_zero++;
            else cnt_one++;
        }
        if(cnt_zero==n) return 0;
        if(cnt_one==n) return n-1;
        //handling other cases
        for(int right=0; right<n; right++){
                 if(nums[right]==0){
                    zeros++;
                 }
                 //capture window size having 1 zero
                 if(zeros==1){
                    maxLen = max(maxLen,right-left+1);
                 }

                 //shrink the window till there's is 1 zero only
                 while(zeros>1){
                    if(nums[left]==0){
                        zeros--;
                    }
                    left++;
                 }

        }
        return maxLen-1; // after removing 1 zero
    }
};


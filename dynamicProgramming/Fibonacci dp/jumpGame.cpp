/*RECURSION*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int i=0;

        for(int i=0;i<=sum;i++){
            if(i==n-1){
                return true;
            }else{
                sum=max(sum,nums[i]+i);
            }
         }
         return false;
    }
};
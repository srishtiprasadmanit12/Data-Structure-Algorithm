class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      int n=nums.size();
      int sum=0;
      int left=0;
      int right=0;
      for(int i=0;i<n;i++){
        sum+=nums[i];
      }
      //Left prefix sum
      right=sum;
      for(int i=0;i<n;i++){
        right=right-nums[i];
        if(left == right){
            return i;
        }        
        left+=nums[i];
      }
      return -1;  
    }
};
/*
nums = [1,7,3,6,5,6]
left_sum   = [1,8,11,17,22,28] 
right_sum  = [28,27,20,17,11,6]

17 is the match , hence that is pivot 
*/
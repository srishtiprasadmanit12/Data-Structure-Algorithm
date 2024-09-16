class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
      int n=nums.size();
      int l=0,r=n-1;
      while(l<=r){
        int mid = l+(r-l)/2;
        if(target>nums[mid]){
            l=mid+1;
        }
        else if(target<nums[mid]){
            r=mid-1;
        }
        else{
            return mid;
        }
      }  
      return l;
    }
};
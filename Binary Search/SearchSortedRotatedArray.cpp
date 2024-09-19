class Solution {
public:
    int search(vector<int>& nums, int target) {
       //either left is sorted or right
       int n = nums.size();
       int l = 0;
       int r = n-1; 
       while(l<=r){
        int mid = (l+r)/2;

        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>=nums[l]){
            //sorted rotated array : If left is sorted
            //then we'll check if target is between this range of out of this range
            if(nums[l]<=target && target<=nums[mid]){
                r = mid-1;
            }else{
                l=mid+1;
            }
        }
        else{
            //Sorted rotated array : If right is sorted
            //then we'll check if target is between this range of out of this range
            if(target>=nums[mid] && target<=nums[r]){
                l = mid+1;
            }else{
                r=mid-1;
            }
        }

       }
       return -1;
    }
};
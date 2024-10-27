class Solution {
public:
    int binarySearch(vector<int>& nums, int target,bool isSearchLeft){
        int l=0,r=nums.size()-1,idx=-1;
        while(l<=r){
            int mid = l +(r-l)/2;
            if(target<nums[mid]){
                r=mid-1;
            } else if(target>nums[mid]){
                l=mid+1;
            }else{
                idx=mid;
                if(isSearchLeft){
                    //once you get the target idx, search for leftmost target value
                    r=mid-1;
                }else{
                    //once you get the target idx, search for rightmost target value
                    l=mid+1;
                }
            }
        }
        return idx;

    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans = {-1,-1};
        int left = binarySearch(nums,target,true);
        int right = binarySearch(nums,target,false);
        // ans.assign({left,right});
        ans[0]=left;
        ans[1]=right;
        return ans;
    }
};
/*
[5,7,7,8,8,10] m = 2.5
       l m   r

[5,7,8,8,8,8,10] 

*/
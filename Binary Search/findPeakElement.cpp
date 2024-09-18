/*************************BRUTE FORCE APPROACH************************* */ 
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    if(n==1){
        return 0;
    } 
    if(nums[0]>nums[1]){
        return 0;
    }
    if(nums[n-1]>nums[n-2]){
        return n-1;
    }
    int ans = 0;   
    //O(N)
    for(int i=1;i<n-1;i++){
        if(nums[i-1]<nums[i] && nums[i]>nums[i+1]){
            ans = i;
            break;
        }
    }
    return ans;
    }
};
/**************************OPTIMISED O(logn)************************** */
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return 0;
        }
        if(nums[0]>nums[1]){
            return 0;
        }
        if(nums[n-1]>nums[n-2]){
            return n-1;
        }
        int start=0;
        int end = n-2;
        while(start<end){
            int mid = start + (end - start)/2;
            if(nums[mid]>nums[mid+1]){
                end=mid;
            }
            else{
                start=mid+1;
            }
        }
        return start;
    }
};
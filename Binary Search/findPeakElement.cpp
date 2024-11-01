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

//Apply binary search on indices of array and not on their values 
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
        //Aim will be to check if our mid is peak element
        //in this ques, we dont need to check boundary condition inside while loop, hence start<end and not start<=end
        while(start<end){
            int mid = start + (end - start)/2;
            //crux:what value are we going to compare from nums[mid] 
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
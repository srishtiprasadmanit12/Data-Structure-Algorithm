/*
step 1 : a[i]<a[i+1] ==> idx1=i(1)
break;

4   1   5   3   2
<---------------

step 2 : find index of elemnt just bigger than a[idx] (here idx2=4)

step 3:  swap idx1 & idx2 , 4 2 5 3 1

step 4:  sort the number from last to idx1

4   2   1   3   5 --> next permutation

*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       if(nums.size()==1){
        return;
       } 

       int idx1;
       for(int i=nums.size()-2;i>=0;i--){
            if(nums[i+1]>nums[i]){
                idx1=i;
                break;
            }
       }

       if(idx1<0){
        reverse(nums.begin(),nums.end());
       }
       else{
        int idx2=0;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]>nums[idx1]){
                idx2=i;
                break;
            }
        }
        swap(nums[idx1],nums[idx2]);
        sort(nums.begin()+idx1+1,nums.end());
       }
    }
};
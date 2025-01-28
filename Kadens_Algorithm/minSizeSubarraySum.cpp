//Brute Force
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int curr=0;
        int diff=0;
        int minDiff=INT_MAX;

        for(int i=0;i<n;i++){
            curr = 0;
            // diff=0;
            for(int j=i;j<n;j++){
                curr+=nums[j];
                diff = j-i+1;
                if(curr>=target){
                   minDiff = min(diff,minDiff);  
                }
            }            
        }
        return minDiff==INT_MAX?0:minDiff;
    }
};

//Kaden's algorithm

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int minDiff=INT_MAX;
        int i=0,curr=0;
        int diff=0;

        for(int j=0;j<n;j++){
            curr+=nums[j];

            while(curr>=target){
                minDiff = min(minDiff,j-i+1);
                curr= curr-nums[i];
                i++;
            }
        }
        return minDiff==INT_MAX?0:minDiff;
    }
};
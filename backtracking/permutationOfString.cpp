/*
Permutation of string
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

total permutation of nums = [1,2,3] is n!= 3!=6
solution explanation - https://takeuforward.org/data-structure/print-all-permutations-of-a-string-array/

We run a loop from 0->n-1 , check if frequency is unmarked,if its unmarked it hasn't been picked 
and we pick it & make sure it is marked

call recursion to pick other parameters, when we come back from recursion we unmark the element 
in map remove from data structure (here array)

*/
class Solution {
public:
    void solve(vector<int>&ds,vector<int>&freq,vector<int>& nums,vector<vector<int>>&ans){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }

// Basic Approach - start with a number and then find permutation of rest digits 
        for(int i=0;i<nums.size();i++){
            //if 0th postion of array is 0, then
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i]=1;
                solve(ds,freq,nums,ans);
                freq[i]=0;
                ds.pop_back();
            }   
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>ds;
        vector<int>freq(n,0);//map to maintain visited element,initialize it with 0
        
        solve(ds,freq,nums,ans);
        return ans;

    }
};
/*
                RECURSIVE TREE

     ---------------1,2,3]-------------
    /               |                  |          
  [1]               [2]                [3]           ==>(start with these digits)
  /   \           /    \               /  \
[1,2]  [1,3]    [2,1]  [2,3]        [3,1]  [3,2]
|       |          |      |            |      |
[1,2,3] [1,3,2]  [2,1,3]  [2,3,1]   [3,1,2]  [3,2,1]




*/
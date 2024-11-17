/*
output: [[123],[12],[13],[23],[1],[2],[3]] 
Input: [1,2,3]
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;

        createSubset(nums, 0, res, subset);
        return res;        
    }

    void createSubset(vector<int>& nums, int index, vector<vector<int>>& res, vector<int>& subset) {
        if (index == nums.size()) {
            res.push_back(subset);
            return;
        }

        //include
        subset.push_back(nums[index]);
        createSubset(nums, index + 1, res, subset);

        //exclude
        //first we have to remove last element then we can call exclude part , dry run tree for better understanding
        subset.pop_back(); //backtrack 
        createSubset(nums, index + 1, res, subset);
    }    
};

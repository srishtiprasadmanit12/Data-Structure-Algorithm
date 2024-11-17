## BACKTRACKING
Backtracking is a problem-solving strategy that involves recursively exploring all possible solutions to a problem, and then backtracking to the previous state when a dead end is reached.

basic terms we can say , we are reverting a particular change when returning  which we did while making function call.

#### RAT IN A MAZE
```cpp

```

 [Subset : leetcode]( https://leetcode.com/problems/subsets/description/?envType=problem-list-v2&envId=backtracking)

### SUBSET

```cpp
                        []
                    in/    \ex
                   [1]       []
                in/    \ex  /    \
             [1,2]    [1]  [2]     []
            /     \   /    \       /    \
      [1,2,3]  [1,2] [2,3]  [2]  [3]     []
      

```


```cpp
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

```

```cpp
/*
input:"abc",
output:["", "a", "b", "ab", "c", "ac", "bc", "abc"]
*/
void subseq(string &s1,vector<string>&ans,int idx,string &s2){
    //base
    if(idx==s1.size()){
        ans.push_back(s2);
        return;
    }
    //include
    s2.push_back(s1[idx]);
    subseq(s1,ans,idx+1,s2);

    //exclude
    s2.pop_back(); //pop or remove
    subseq(s1,ans,idx+1,s2);
}
int main(){

    string s1="abc";
    vector<string>ans;
    string s2="";
    subseq(s1,ans,0,s2);
    
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}
```


## observation:1 
If question says find all possible subset, substring --> these type of question fall under backtracking
constrain is very small as when we use recursion(backtracking) 2^n would pass test case.

Total n length and har index pe you have two options to explore , this is 2^n time complexity

## template of backtracking

1.DO
2.Explore
3.undo



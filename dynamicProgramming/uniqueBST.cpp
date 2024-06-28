//MERGE INTERVALS

//RECURSIVE APPROACH 
//TC : O(3^N)
class Solution {
public:
    int numTrees(int n) {
        if(n<=1){
            return 1;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+= numTrees(i-1)*numTrees(n-i);
        }
        return ans;
    }
};

//MEMOISED APPROACH 
//TC : O(N*N)

class Solution {
public:
    int dp[20]={0}; 
    int numTrees(int n) {
        if(n<=1){
            return 1;
        }
        if(dp[n]){
            return dp[n];
        }
        for(int i=1;i<=n;i++){
            dp[n]+= numTrees(i-1)*numTrees(n-i);
        }
        return dp[n];
    }
};
/*
Recursion Tree
n = 3

root        1           2           3
        i-1 n-i        1  1         2  0
        0   2          1  3         


root        1           2           3           4           5
i-1 n-i   0  4         1  3       2   2       3  1         4  0
            3 1

                   
        1               2            2
          5            1 3         1    5
         4                4            3
        3                 5           4
       2 

*/
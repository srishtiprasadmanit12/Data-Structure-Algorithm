//RECURSION
class Solution {
public:
    int ways(int r,int c){
        if(r==0 && c==0)
            return 1;
        if(r==1 && c==0 || r==0 && c==1){
            return 1;
        }
        if(r<0 ||c<0){
            return 0;
        }
            return ways(r,c-1)+ways(r-1,c);

    }
    int uniquePaths(int m, int n) {
        return ways(m-1,n-1);
    }
};
//MEMOISATION
class Solution {
public:
    int ways(int r,int c,vector<vector<int>>& dp){
        if(r==0 && c==0)
            return 1;
        if(r==1 && c==0 || r==0 && c==1){
            return 1;
        }
        if(r<0 ||c<0){
            return 0;
        }
        if(dp[r][c]!=-1)
            return dp[r][c];
        return dp[r][c] = ways(r,c-1,dp)+ways(r-1,c,dp);

    }
    int uniquePaths(int m, int n) {
         vector<vector<int>> dp(m, vector<int>(n, -1));
        return ways(m-1,n-1,dp);
    }
};
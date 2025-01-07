/*RECURSION*/

class Solution {
public:
    int climbStairs(int n) {
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }

        return climbStairs(n-1)+climbStairs(n-2);
    }
};

/*DYNAMIC PROGRAMMIG*/

class Solution {
public:
    int dp[46];
    int climb(int n) {
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n]= climb(n-1)+climb(n-2);
        return dp[n];
    }
    int climbStairs(int n){
        memset(dp,-1,sizeof(dp));
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        return climb(n);
    }
};
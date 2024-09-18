//RECURSION
class Solution {
public:
    int climbingStairs(vector<int>& cost,int idx){
        if(idx < 0) 
            return 0;
        if(idx==0 || idx==1) 
            return cost[idx];
        int one = cost[idx]+climbingStairs(cost,idx-1);
        int two =  cost[idx]+climbingStairs(cost,idx-2);

        return min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return min(climbingStairs(cost,n-1),climbingStairs(cost,n-2));
    }
};


//MEMOISATION
class Solution {
public:
    int climbingStairs (vector<int>& cost,int idx,int dp[]){
        if(idx < 0) 
            return 0;
        if(idx==0 || idx==1) 
            return cost[idx];
        if(dp[idx]!=-1)
            return dp[idx];
        
        int one = cost[idx]+climbingStairs(cost,idx-1,dp);
        int two =  cost[idx]+climbingStairs(cost,idx-2,dp);

        return dp[idx]=min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp[n];
        memset(dp,-1,sizeof(dp));
        return min(climbingStairs(cost,n-1,dp),climbingStairs(cost,n-2,dp));
    }
};
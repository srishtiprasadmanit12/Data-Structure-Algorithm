//RECURSIVE
class Solution {
public:
    
    int Mincoin(vector<int>& coins, int amount){
        if(amount<=0) 
            return 0;
        int ans=INT_MAX; // this was the main nudge of this question,we want to re-initialize everytime
        for(int i=0;i<coins.size();i++){
            if(amount-coins[i]>=0){
                 ans = min(ans+0LL,Mincoin(coins,amount-coins[i])+1LL);                
                }              
        }
        return ans;
    }
    int coinChange(vector<int>& coins, int amount) {
           int n = coins.size();
           int ans = Mincoin(coins,amount);
           if(ans==INT_MAX)
                return -1;
            else
            return ans;
                 
    }
};
/*
                          11
                    10     9      6
                [9 8 5]  [8,7,4]  [5,4,1]
            []  []  [] 

*/



//DYNAMIC PROGRAMMING -  MEMOISATION

class Solution {
public:
    
    int Mincoin(vector<int>& coins, int amount,vector<int>&dp){
        if(amount<=0) 
            return 0;
        if(dp[amount]!=-1) {
            return dp[amount];
        }
        int ans=INT_MAX; // this was the main nudge of this question,we want to re-initialize everytime
        for(int i=0;i<coins.size();i++){
            if(amount-coins[i]>=0){
                 ans = min(ans+0LL,Mincoin(coins,amount-coins[i],dp)+1LL);                
                }              
        }
        return dp[amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
           int n = coins.size();
           vector<int>dp(amount+1,-1);
           int ans = Mincoin(coins,amount,dp);
           if(ans==INT_MAX)
                return -1;
            else
            return ans;
                 
    }
};
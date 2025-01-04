/*Here we have used loop , which is correct , 
we could have also done by passing index of coins array in recursive call */

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

// BOTTOM UP APPROACH 

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
     int n = coins.size();
     vector<int>dp(amount+1,INT_MAX-1);
    //INT_MAX-1 is good way to prevent overflow 
     dp[0]=0;
     for(int coin:coins){
        for(int j=coin;j<=amount;j++){
            dp[j]=min(dp[j],1+dp[j-coin]);
        }
     } 
     return dp[amount]>=INT_MAX-1?-1:dp[amount];  
    }
};

/*
By passing index in recursive call
*/

//RECURSION
class Solution {
public:
    int solve(vector<int>&coins,int amount,int n){
        if(amount==0){
            return 0;
        }
        if(n==0){
            //THIS base case is imp, becoz at this point amount!=0 & n==0, hence ans is not possible
            return INT_MAX;
        }
        int ans=INT_MAX;
        if(coins[n-1]>amount){
            ans = solve(coins,amount,n-1);
        }else{
         ans = min(1LL+solve(coins,amount-coins[n-1],n),0LL+solve(coins,amount,n-1));
        }
        return ans;
        
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0){
            return 0;
        }
        int n = coins.size();
        int res = solve(coins,amount,n);
        return res==INT_MAX?-1:res;
    }
};
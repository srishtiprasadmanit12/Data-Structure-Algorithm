/*
Problem statement
You are given ‘n’ items with certain ‘profit’ and ‘weight’ and a knapsack with weight capacity ‘w’.

You need to fill the knapsack with the items in such a way that you get the maximum profit. You are allowed to take one item multiple times.

Example:
Input: 
'n' = 3, 'capacity' = 10, 
'val' = [5, 11, 13]
'wt' = [2, 4, 6]

*/


int recur_knapsack(int i,int val[],int wt[],int cap){
    if(i==val.size()){
        return 0;
    }
    int take=0;

    if(wt[i]<=cap){
        take = val[i] + recur_knapsack(i,val,wt,cap-wt[i]);
    }

    //skip current item
    int notake = recur_knapsack(i+1,val,wt,cap); // wt[i] > cap

    //return max of the two
    return max(take,notake); 
    
}

int memo_knapsack(int i,int val[],int wt[],int cap,vector<vector<int>>&dp){
    if(i==val.size()){
        return 0;
    }

    if(dp[i][cap]!=-1){
        return dp[i][cap];
    }

    int take = 0;

    if(wt[i]<=cap){
        int take = val[i] + memo_knapsack(i,val,wt,cap-wt[i],dp); 
    }

    int notake = memo_knapsack(i+1,val,wt,cap,dp);

    return dp[i][cap] = max(take,notake);
}

int tab_knapsack(int val[],int wt[],int cap){
    vector<vector<int>>dp(val.size()+1,vector<int>(cap+1,0));
    for(int i=val.size()-1;i>=0;i--){
        for(int j=1;j<=cap;j++){
            int take = 0;
            if(j-wt[i]>=0){
                take = val[i]+dp[i-j-wt[i]];
            }
            int notake = dp[i+1][j];
            dp[i][j] = max(take,notake);    
        }
    }
    return dp[0][cap];
}
int main(){
    int n, w;
    cin >> n >> capacity;
    int val[n], wt[n];
    for(int i = 0; i < n; i++) {
        cin >> val[i] >> wt[i];
        }   
    
    //recursive approach
    return recur_knapsack(0,val,wt,capacity);

    //memoised approach
    vector<vector<int>>dp(val.size(),vector<int>(capacity+1,-1));
    return memo_knapsack(0,val,wt,capacity,dp);

    //tabulation
    return tab_knapsack(val,wt,capacity);


}

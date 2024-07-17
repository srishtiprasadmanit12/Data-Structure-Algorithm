//RECURSION
int lcs_recursion(string str1,string str2,int n,int m){
    if(n==0 || m==0)
        return 0;
    int ans = lcs_recursion(n,m-1);
    ans = max(ans,lcs_recursion(n-1,m));
    ans = max(ans,lcs_recursion(n-1,m-1)+(str1[i]==str2[j]));

    return ans;
}
/*
            ABC,AFC
    AB          ABC         AB
    AFC         AF          AF

*/
//MEMOISATION
int lcs_memo(string str1,string str2,int n,int m,vector<vector<int>> &dp){
   if(n==0 || m==0){
    return 0;
   } 
   if(dp[n][m]!=-1){
    return dp[n][m];
   }
   int ans = lcs_memo(n,m-1,dp);
   ans = max(ans,lcs_memo(n-1,m,dp));
   ans = max(ans,lcs_memo(n-1,m-1,dp)+(str1[n]==str2[m]));

   return dp[n][m]=ans;
}

//TABULATION

int lcs_tabulation(string str1,string str2,int n,int m){
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
                }
                else if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    }
                    else{
                        dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
                        }
        }
                    
    }               
    return dp[n][m];         
}
/*
              A   b   c
        0     0   0   0 
    a   0     1   1   1
    f   0     1   1   1
    c   0     1   1   2
*/
vector<vector<int>>dp(n,vector<int>(m,0))
int main(){
    string str1 , str2;
    cin>>str1>>str2;
    int n = str1.size();
    int m = str2.size();
    int dp[n+1][m+1];
    memset(dp,-1,sizeof(dp));
    return lcs_recursion(str1,str2,n-1,m-1);
    return lcs_memo(str1,str2,n-1,m-1,dp);
    return lcs_tabulation(str1,str2,n-1,m-1);

}

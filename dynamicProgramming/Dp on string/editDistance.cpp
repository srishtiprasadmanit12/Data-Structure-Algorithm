//RECURSION
class Solution {
public:
    int editDistance(string &word1,int i,string &word2,int j){
        
       
            if(i==word1.size())
                return word2.size()-j;
             if(j==word2.size())
                return word1.size()-i;
            
        if(word1[i]==word2[j]){
            return editDistance(word1,i+1,word2,j+1);
        }
        else{
            int insert = 1+editDistance(word1,i,word2,j+1);
            int del = 1+editDistance(word1,i+1,word2,j);
            int replace = 1+editDistance(word1,i+1,word2,j+1);
            return min({insert,del,replace});
        }
        
    }
    int minDistance(string word1, string word2) {
        int n1= word1.size();
        int n2= word2.size();

       return editDistance(word1,0,word2,0);

    }
};
=============================================================================================
//MEMOISATION - DP

class Solution {
public:
    int editDistance(string &word1,int i,string &word2,int j,vector<vector<int>>&dp){
        
       
            if(i==word1.size())
                return word2.size()-j;
             if(j==word2.size())
                return word1.size()-i;
            if(dp[i][j]!=-1){
                return dp[i][j];
            }
        if(word1[i]==word2[j]){
             dp[i][j] = editDistance(word1,i+1,word2,j+1,dp);
        }
        else{
            int insert = 1+editDistance(word1,i,word2,j+1,dp);
            int del = 1+editDistance(word1,i+1,word2,j,dp);
            int replace = 1+editDistance(word1,i+1,word2,j+1,dp);
            dp[i][j]= min({insert,del,replace});
        }
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        int n1= word1.size();
        int n2= word2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
       return editDistance(word1,0,word2,0,dp);

    }
};
============================================================================================
//TABULATION


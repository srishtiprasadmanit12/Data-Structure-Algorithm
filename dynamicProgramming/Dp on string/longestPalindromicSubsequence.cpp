//Longest palindromic subsequence

//RECURSION
class Solution {
public:
    int LPS(int j,int i,string s){
        if(i>j){
            return 0;
        }
        if(i==j)
            return 1;
        if(s[i]==s[j])
            return LPS(j-1,i+1,s)+2;
        return max(LPS(j-1,i,s),LPS(j,i+1,s));
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        return LPS(n-1,0,s);
    }
};

// MEMOISATION 
// Here I've used LCS approach by reversing a string

class Solution {
public:
    int dp[1005][1005];
    int LPS(int j,int i,string&s,string &rev){
         
        if(i<0||j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(s[i]==rev[j])
            dp[i][j] = 1+LPS(j-1,i-1,s,rev);
        else
            dp[i][j] = max(LPS(j-1,i,s,rev),LPS(j,i-1,s,rev));

        return dp[i][j];
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        memset(dp,-1,sizeof(dp));
        string rev = s;
        reverse(rev.begin(),rev.end());
        return LPS(n-1,n-1,s,rev);
    }
};

  
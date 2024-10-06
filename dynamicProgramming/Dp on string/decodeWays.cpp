class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        
        if (n == 0 || s[0] == '0') return 0;  // if first char is '0', no valid decoding
        
        vector<int> dp(n+1, 0); // dp[i] means the number of ways to decode up to index i
        dp[0] = 1; // There's 1 way to decode an empty string
        
        for (int i = 1; i <= n; i++) {
            // Check if the single digit s[i-1] is valid (1-9)
            if (s[i-1] != '0') {
                dp[i] += dp[i-1];
            }
            
            // Check if the two-digit substring s[i-2:i] is valid (10-26)
            if (i > 1 && (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6'))) {
                dp[i] += dp[i-2];
            }
        }
        
        return dp[n];
    }
};
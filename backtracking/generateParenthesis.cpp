class Solution {
public:
    void solve(int n, int open, int close, string output, vector<string>&ans){
        if(open == n && close == n){
            ans.push_back(output);
            return;
        }

        if(open!=n){
            solve(n,open+1,close,output+"(",ans);
        }
        if(open>close){
            solve(n,open,close+1,output+")",ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string output;
        solve(n,0,0,output,ans);
        return ans;
    }
};

/*
                         ""
                        /  \
                     "("    ")"
                    /        \
                 "(("         "()"
                  |            |   \
                 "(()"       "()"  backtrack
                  |             |
                "(())"         "()("
                                 |
                                "()()"

*/
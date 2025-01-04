/*  
    Unique Length-3 Palindromic Subsequences
*/

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        int ans=0;
        unordered_map<char,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[s[i]].push_back(i); // since second parameter type is vector in map hence push_back() is used
        }
        for(auto x:mp){
            //first & last idx of occurence of x
            int l = x.second[0];
            int r = x.second[x.second.size()-1];
            if(r-l>1){ // to find 3 letter palindrome
            vector<bool>vis(26,false);
            for(int i=l+1;i<r;i++){//number of unique letters is the no.of unique 3 lettered palindrome
                if(vis[s[i]-'a']){
                    continue;
                }
                ans++;
                vis[s[i]-'a']=true;
            }
            }

        }
        return ans;
    }
};
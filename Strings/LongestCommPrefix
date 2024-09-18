/*
After sorting alphabetically, only the first and last sets of strings need to be considered, 
and if they do not match, just empty the set. If the conditions are met, the middle string 
will have the same prefix for sorting reasons
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        sort(strs.begin(),strs.end());
        int n = strs.size();
        string first=strs[0];
        string last = strs[n-1];
        for(int i=0;i<min(first.size(),last.size());i++){
            if(first[i]!=last[i]){
                return ans;
            }
            ans+=first[i];
        }
        return ans;
    }
};
class Solution {
public:
    void solve(string &output,int i,vector<string>&ans,string map[],string digits){
        if(i>=digits.size()){
            ans.push_back(output);
            return;
        }
        int num = digits[i]-'0';
        string value = map[num];
        for(int j=0;j<value.size();j++){
            output.push_back(value[j]);
            solve(output,i+1,ans,map,digits);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        int n = digits.size();
        if(n==0){
            return ans;
        }
        string output;
        string map[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(output,0,ans,map,digits);
        return ans;
    }
};
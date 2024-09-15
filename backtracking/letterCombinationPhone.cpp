class Solution {
private:
    void solve(string digit,string output,int i,vector<string>&ans,string map[]){
        if(i>=digit.size()){
            ans.push_back(output);
            return;
        }

        int num = digit[i] - '0';
        string value = map[num];

        for(int j=0;j<value.size();j++){
            output.push_back(value[j]);
            solve(digit,output,i+1,ans,map);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
     vector<string>ans;
     if(digits.size()==0){
        return ans;
     }
     int i=0;
     string output;
     // Array of string
     string map[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
     solve(digits,output,i,ans,map);
     return ans;
    }
};
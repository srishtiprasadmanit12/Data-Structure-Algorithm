class Solution {
public:
    stack<char>processStack(stack<char>&stk,string s){
        int n=s.size();
        for(int i=0;i<n;i++){
                if(s[i]=='#'&& !stk.empty()){
                    stk.pop();
                }
                if(s[i]!='#') stk.push(s[i]); // we'll only push in stack if charecter is not '#'
            }
        return stk;
    }
    bool backspaceCompare(string s, string t) {
        stack<char>stk1,stk2;
        stk1=processStack(stk1,s);
        stk2=processStack(stk2,t);
       
       return stk1==stk2;
    }
};
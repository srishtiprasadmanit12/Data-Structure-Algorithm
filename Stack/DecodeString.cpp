class Solution {
public:
    string decodeString(string s) {
      stack<char>stk;
       for(int i=0;i<s.size();i++){
        if(s[i]!=']'){
            stk.push(s[i]);
        } 
        else{
            //"["
            string curr_str = "";
            while(stk.top()!='['){
                curr_str=stk.top()+curr_str;
                stk.pop();
            }
            stk.pop(); // pop '['
            string num = "";
            //if number is more than 1 digit
            while(!stk.empty() && isdigit(stk.top())){
                num = stk.top() + num;
                stk.pop();
            }
            int k = stoi(num);
            while(k--){
                for(int i=0;i<curr_str.size();i++){
                    stk.push(curr_str[i]);
                }
            }
        }
       }
        s= "";
        while(!stk.empty()){
            s=stk.top()+s;
            stk.pop();
        }
        return s;
    }
};
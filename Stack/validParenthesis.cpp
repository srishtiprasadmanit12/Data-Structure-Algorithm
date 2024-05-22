class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]=='['||s[i]=='{') {
                st.push(s[i]);
            }
            else if(!st.empty() && ((s[i]==')' && st.top()=='(') ||
                     (s[i]==']' && st.top()=='[')||
                     (s[i]=='}' && st.top()=='{')))
                     
            {
                 st.pop();
            }
            else{ 
                return false;
                }
        }
       if(st.empty()) return true;
       else return false;

    }
};

/*
positive cases
1.()
2.[],(),{}
3.{[()]}
negative cases
1.(){}}{
2.{[(})
3.]

If bracket -> open -> push in stack
If close bracket -> pop from stack ->& top most element is not of same type -> false 

also before poping out element from stack we need to ensure that stack must have element 
else it will give runtime error

*/
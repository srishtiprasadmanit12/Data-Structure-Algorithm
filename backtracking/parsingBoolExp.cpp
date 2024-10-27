class Solution {
public:
    bool parseBoolExpr(string exp) {
        int n = exp.size();
        stack<char>stk;
        for(char e: exp){
            if(e == ')'){
                vector<char>subExp;
                //pop until u get opening bracket
                while(stk.top()!='('){
                    char x = stk.top();
                    stk.pop();
                    subExp.push_back(x);
                }

                stk.pop();//pop opening bracket
                char oper  = stk.top();
                stk.pop();//pop operator

                //now 3 cases arises

                //case 1 : when operator is |
                if(oper == '|'){
                    char result = 'f';
                    //loop in subExp
                    for(auto ch:subExp){
                        if(ch == 't'){
                            result = 't';
                            break;
                        }
                    }
                    stk.push(result);

                }
                
                //case 2 : when operator is &
                else if(oper == '&'){
                   char result = 't';
                   for(auto ch:subExp){
                    if(ch == 'f'){
                        result = 'f';
                        break;
                    }
                   } 
                   stk.push(result);
                }
                
                //case 1 : when operator is !
                else if(oper == '!'){
                    stk.push(subExp[0]=='t'?'f':'t');
                }



            }else if(e!=','){
                //push everything in stack
                stk.push(e);
            }
        }
        return stk.top() == 't'; // if top is 't' return true else false 
    }
};
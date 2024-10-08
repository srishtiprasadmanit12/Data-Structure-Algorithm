/*
For this particular ques we could have used stoi() method but it has few limitations
string str = "geek13";
cout<< stoi(str);
=======> error <=========
The above code will throw an exception because stoi() function does not support strings that contain non-numeric
characters. It will only work with strings that contain numeric characters. So we have to use a loop

*/

class Solution {
public:
    int myAtoi(string s) {
        long long int ans=0;
        int i=0;

        //skip leading white spaces
        while(s[i]==' ')
            i++;
        
        int sign = 0; // 0-> + , 1->-

        //handle sign 
        if(s[i]=='-'){
            sign = 1;
            i++;
        }else if(s[i]=='+'){
            sign = 0;
            i++;
        }

        //skip leading zeroes
        while(s[i]=='0')
            i++;
        
        //convert character to integer
        while(s[i]>='0' && s[i]<='9'){
            //If result value exceed given value we've to show upper value
            if(ans >INT_MAX){
                if(sign)
                    return INT_MIN;
                else
                    return INT_MAX;
            }

            ans = ans * 10 + s[i]-'0';
            i++;
        }
        
        if(sign){
            ans *= -1;
        }

        //handle overflow/underflow
        if(ans > INT_MAX) return INT_MAX;
        if(ans < INT_MIN) return INT_MIN;

        return (int) ans;
    }
};
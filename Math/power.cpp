/*

2^10 = (2*2)^5 = (4)^5

4* (4*4)^2

4 * (16*16)^1

4* 256

1024 ==> ans 

for even power keep on multiplying & and making power half
for odd power remove one number & rest will be even power left as 4^5 => 4 * (4*4)^2

*/

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long power = n;

        if(n<0){
            //make it positive
            power = -1*power;
        }

        while(power){
            if(power%2){
                //if pow is odd
                ans = x * ans;
                power = power-1;

            }
            else{
                x = x*x;
                power = power/2;
            }
        }
        if(n<0){
             ans = (double)1.0/double(ans);
        }
        return ans;
    }
};
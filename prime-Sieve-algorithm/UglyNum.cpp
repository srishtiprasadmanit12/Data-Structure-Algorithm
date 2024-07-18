//An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
//return true if its ugly number otherwise false;

class Solution {
public:
    bool isUgly(int n) {
        if(n<1){
            return false;
        }
        int ugly[]={2,3,5};
        for(int i=0;i<3;i++){
            while(n%ugly[i] == 0){
                n=n/ugly[i];
            }
        }
        if(n==1)
            return true;
        return false;
    }
};
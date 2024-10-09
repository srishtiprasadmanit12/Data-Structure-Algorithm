class Solution {
public:
    int minSwaps(string s) {
        int cnt=0;
        for(auto &x:s){
            if(x == '['){
                cnt++;
            }else if(cnt>0){
                // here closing bracket will fall
                cnt--;
            }
        }
        return (cnt+1)/2;

    }
};
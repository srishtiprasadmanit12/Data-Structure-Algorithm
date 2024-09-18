class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        int i =0,j=0;
        if(m==0)
            return 0;

       while(i<n){
        if(needle[j]!=haystack[i]){
           i= i-j+1;
           j=0;
        }else{
            i++;j++;
            if(j==m){
                return i-j;
            }
        }
       }
       return -1;
    }
};
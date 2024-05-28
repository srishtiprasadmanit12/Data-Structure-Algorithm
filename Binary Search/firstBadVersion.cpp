// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long left =0;
        long long right = n;
        long long ans=0;
        while(left<=right){
            long long mid =left+ (right-left)/2;
            if(isBadVersion(mid)){
                right = mid - 1;
                ans = mid;
            }else{
                left = mid+1;
            }
        }
        return ans;
    }
};
/*

there are 5 version, we have to check 1st bad version
x   x   x   x   x
since we need to minimize api call , we'll use binary search
Binary search  -> mid -> good version -> move to right 
Binary search  -> mid -> bad version -> move to left to check 1st bad version

*/

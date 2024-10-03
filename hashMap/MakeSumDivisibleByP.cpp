class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long totalSum = 0;
        for(int i=0;i<nums.size();i++){
            totalSum+=nums[i];
        }

        // Edge Case handle
        int rem = totalSum%p;
        if(rem == 0) return 0;

        unordered_map<int,int>mp;
        mp[0]=-1;
        long prefixSum = 0;
        int minLen = nums.size();

        for(int i=0;i<nums.size();i++){
            prefixSum+=nums[i];
            int currentMod = prefixSum % p;
            int targetMod = (currentMod - rem + p)%p;

            if(mp.find(targetMod)!=mp.end()){
                minLen = min(minLen, i - mp[targetMod]);
            }
            mp[currentMod] = i;
        }
        return minLen == nums.size() ? -1:minLen;
    }
};
/*
[3,1,4,2]

3 -> 3%6 = 3 (3-4+6)%6 = 1
1 -> 4%6 = 4  
4 -> 8%6 = 2
2 -> 10%6= 40

*/
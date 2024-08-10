class Solution {
public:
    int compress(vector<char>& nums) {
        int ans=0;

        for(int i=0;i<nums.size();){
            char letter = nums[i];
            int cnt=0;

            while(i<nums.size() && nums[i]==letter){
                cnt++;
                i++;
            }

            nums[ans]=letter;
            ans++;

            if(cnt>1){
                for(auto& c:to_string(cnt)){
                    nums[ans]=c;
                    ans++;
                }
            }
        }
        return ans;
    }
};
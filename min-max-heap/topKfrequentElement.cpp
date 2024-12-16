class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;   
        }

        priority_queue<pair<int,int>>pq;
        for(auto x:mp){
            pq.push({x.second,x.first});
        }

        vector<int>ans;
        while(!pq.empty() && k>0){
            auto x = pq.top();
            pq.pop();
            ans.push_back(x.second);
            k--;
        }
        return ans;
    }
};
/*
unordered_map --> number , freq

pq --> max heap of pair (freq,number)

Iterate for k elements and store in vector 

*/
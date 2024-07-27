

////////////////////////IMPORTANT QUESTION \\\\\\\\\\\\\\\\\\\\\\\\
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<pair<int,int>>vec(n);
        for(int i=0;i<n;i++){
            vec[i]={nums2[i],nums1[i]};
        }
        sort(vec.begin(),vec.end()); // sort vec on the basis of nums2 ,since we need min
        priority_queue<int,vector<int>, greater<int>>pq; //min heap
        long long sum =0;
        long long ans = 0;
        for(int i=n-1;i>=0;--i){
           pq.push(vec[i].second);
           sum+=vec[i].second; 

           if(pq.size()>k){
            sum=sum - pq.top();
            pq.pop();
           }

           if(pq.size()==k){
            ans= max(ans,sum*(vec[i].first));
           }
        }
        return ans;

    }
};

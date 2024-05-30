//optimised binary Search code 
class Solution {
public:
    bool isPossible(int k,vector<int>& piles, int h){
        int hourReq=0;
        for(int i=0;i<piles.size();i++){
            hourReq+=ceil((piles[i]*1.0)/k); 
        }
        return (hourReq<=h);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
      int maxm = *max_element(piles.begin(),piles.end());
      int l=1,r=maxm;
      int ans=0;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(isPossible(mid,piles,h)){
                ans=mid;
               r=mid-1; // we need to find min k, so shift search space to left
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};
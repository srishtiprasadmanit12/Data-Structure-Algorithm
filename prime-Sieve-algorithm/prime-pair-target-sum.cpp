class Solution {
public:
    void findSubset(vector<vector<int>>&ans,vector<int>&prime,int n){
        int i=0,j=prime.size()-1;
        while(i<=j){
            if(prime[i]+prime[j]==n){
                ans.push_back({prime[i],prime[j]});
                i++;
                j--;
            }
            else if(prime[i]+prime[j]<n){
                i++;
            }
            else{
                j--;
            }
        }
    }
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool>isPrime(n,true);
        vector<vector<int>>ans;
        vector<int>prime;
        isPrime[0]=isPrime[1]=false;
        for(int i=2;i<n;i++){
            if(isPrime[i]==true){
                prime.push_back(i);
                for(int j=2*i;j<n;j+=i){
                    isPrime[j]=false;
                }
            }
        }
        //prime vector is already sorted, hence we can take 2 pointer approach
        findSubset(ans,prime,n);
        return ans;
        
    }
};
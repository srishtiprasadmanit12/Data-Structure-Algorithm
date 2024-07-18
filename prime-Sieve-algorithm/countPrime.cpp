class Solution {
public:
    int countPrimes(int n) {
        //this base case is important for all test cases to pass
        if(n<=2){
            return 0;
        }
        vector<int>isPrime(n,1);//consider all number as prime
        int cnt=0;
        isPrime[0]=0;
        isPrime[1]=0;
        for(int i=2;i<n;i++){
            if(isPrime[i]){
                cnt++;
                for(int j=2*i;j<n;j+=i){
                    isPrime[j]=0;
                }
            }
        }
      
        return cnt;
    }
};
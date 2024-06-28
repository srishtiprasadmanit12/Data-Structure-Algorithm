//BINARY SEARCH
class Solution {
    public:
        bool possible(vector<int>&bloomDay, int day, int m, int k){
            //returns wheather its possible to make boq or not
            int cnt=0,boq=0;
            for(int i=0;i<bloomDay.size();i++){
                if(bloomDay[i]<=day){
                    cnt++;//blooming is possible
                }
                else{
                    boq +=cnt/k;
                    cnt = 0;
                }
            }
            boq+=cnt/k;
            if(boq>=m){
                return true;
            }else{
                return false;
            }
        }
        int minDays(vector<int>& bloomDay, int m, int k) {
            int n = bloomDay.size();
            int left = *min_element(bloomDay.begin(),bloomDay.end());
            int right = *max_element(bloomDay.begin(),bloomDay.end());
            int ans=0;
            //impossible case
            long long val = m*1LL*k*1LL;
            if(n <val){
                return -1;
            }
            while(left<=right){
                int mid = left+(right-left)/2;
                if(possible(bloomDay,mid,m,k)){
                    //we'll serch on left
                    right=mid-1;
                }
                else{
                    //search on right
                    left=mid+1;
                }
            }
            return left;
        }
    };
    /*
     bloomDay = [1,10,3,10,2], m = 3, k = 2
     bouquets-> no of boquets
     cnt -> no of flowers
    */

     //BRUTE FORCE
     class Solution {
        public:
            bool possible(vector<int>&bloomDay, int day, int m, int k){
                //returns wheather its possible to make boq or not
                int cnt=0,boq=0;
                for(int i=0;i<bloomDay.size();i++){
                    if(bloomDay[i]<=day){
                        cnt++;//blooming is possible
                    }
                    else{
                        boq +=cnt/k;
                        cnt = 0;
                    }
                }
                boq+=cnt/k;
                if(boq>=m){
                    return true;
                }else{
                    return false;
                }
            }
            int minDays(vector<int>& bloomDay, int m, int k) {
                int n = bloomDay.size();
                int minm = *min_element(bloomDay.begin(),bloomDay.end());
                int maxm = *max_element(bloomDay.begin(),bloomDay.end());
        
                //impossible case
                if(n < m*k){
                    return -1;
                }
                //brute force approach where we are iterating over whole array 
                for(int day=minm;day<=maxm;day++){
                    if(possible(bloomDay,day,m,k)){
                        return day;
                    }
                }
                return -1;
            }
        };
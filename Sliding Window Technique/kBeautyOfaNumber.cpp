//Brute force approach

/* Time complexity -> O(n-k) *O(n)
 Substr -> O(n)
*/
class Solution {
public:
    int divisorSubstrings(int num, int k) {
      string str = to_string(num);  
      int n = str.size();
      int count=0;
      for(int i=0;i<=n-k;i++){
           string s=str.substr(i,k);
        int res = stoi(s);
        if(res!=0 && num%res==0){
            count++;
        }
      }
      return count;
    }
};

/*
Sliding window technique
Time complexity -> O(n)
*/

class Solution {
public:
    int divisorSubstrings(int num, int k) {
    string str = to_string(num); //convert num to string
    int n= str.size();
    int left=0,right=0;
    int count=0;
    string res="";
    while(right<n){
        res+=str[right];
        if(right-left+1<k){
            right++;
        }
        else if(right-left+1==k){
            int nums = stoi(res);
            if(nums!=0 && num%nums==0){
                count++;
            }
    
        res.erase(res.begin());
        left++;
        right++;
        }
    }
    return count;
    }
};

//TIME COMPLEXITY : O(N*K)

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string str = to_string(num);
        int n=str.size();
        int cnt=0;
        for(int i=0;i<n-k+1;i++){
             string temp= "";
            for(int j=i;j<i+k;j++){
                //Capturing window               
                temp+= str[j]; 
            }
            int div = stoi(temp);
            if(div!=0 && num%div==0){
                cnt++;
            }
        }
        return cnt;
    }
};
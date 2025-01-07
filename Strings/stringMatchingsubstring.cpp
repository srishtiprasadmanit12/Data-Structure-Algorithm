class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
     int n = words.size();
     vector<string>ans;

     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j && words[j].find(words[i])!=string::npos){
                ans.push_back(words[i]);
                break; //break out of inner loop
            }
        }
     } 
     return ans;  
    }
};
/*
string::npos 
Is a very big value simply denoted as -1 as as to check if value is not found it will result in = -1

*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      unordered_map<char,int>mp1,mp2;
      int n1=s1.size(),n2=s2.size();
      if(n1>n2) return false;
      int left=0,right=0;
      //1st window 
      while(left<n1){
        mp1[s1[left]]++;
        mp2[s2[right]]++;
        left++;right++;
      }
      if(mp1==mp2) return true; //If we get ans in 1st window, then we'll return from here itself

      //look into remaining part of the string 
      left=0;//now right = n1.size() and we'll continue from here 
      while(right<n2){
        mp2[s2[right]]++;// adding right most charater into map
        mp2[s2[left]]--; // removing left most char of map , sake of creating window
        if(mp2[s2[left]]==0){ // if freq=0, erase that value from map
            mp2.erase(s2[left]);
        } 
        if(mp1==mp2) return true;// check if window/map is same ,then return true
        left++;right++;
      }
      return false;
    }
};
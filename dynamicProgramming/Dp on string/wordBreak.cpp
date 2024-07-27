//BRUTE FORCE APPROACH 
///////////TIME LIMIT EXCEEDED/////////////////
class Solution {
private:
    bool wordBreak(string s, unordered_set<string>&set){
        if(s.size()==0){
            return true;
        }
        for(int i=0;i<s.size();i++){
            if(set.count(s.substr(0,i+1)) && wordBreak(s.substr(i+1),set) ){
                return true;
            }
        }
        return false;

    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>set(wordDict.begin(),wordDict.end());
        return wordBreak(s,set);
    }
};

//////////////////////////DYNAMIC PROGRAMMING- MEMOISATION APPROACH\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

class Solution {
    public:
    bool wordBreak(string& s, vector<string>& wordDict) {
    vector<int> dp(s.length(), 0); // Step 1: Initialize the dp array with zeros
    for (int i = 0; i < s.length(); i++) { // Step 2: Loop through each character in the string s
        for (auto& str : wordDict) { // Step 3: Loop through each word in the word dictionary
            if (i < str.length() - 1) // Step 4: If the current index i is less than the length of the word str minus 1, skip this iteration
                continue;
            if (i == str.length() - 1 || dp[i - str.length()]) // Step 5: Check if the current index matches the end of a word in the dictionary or if dp[i - str.length()] is true
                if (str == s.substr(i - str.length() + 1, str.length())) { // Step 6: Check if the substring of s ending at index i matches the word str
                    dp[i] = 1; // Step 7: Mark dp[i] as true (1) if a match is found
                    break; // Step 8: Break the loop to move to the next character in s
                }
        }
    }
    return dp[s.length() - 1]; // Step 9: Return the value at dp[s.length() - 1], indicating if the entire string can be segmented
}

};
/*
word1 : aabbczz
word2 : abbczzz
*/

class Solution {
public:
    bool closeStrings(string word1, string word2) {
      if(word1.size()!=word2.size())  
            return false;
        vector<int>c1(26,0);
        vector<int>c2(26,0);

        //create frequency vector for both words
        for(int i=0;i<word1.size();i++){
            c1[word1[i]-'a']++;
            c2[word2[i]-'a']++;
        }

// if any of charater is present in one word but not in other then,
        for(int i=0;i<26;i++){
            if(c2[i]==0 && c1[i]!=0)
                return false;
        }
    //Here: sorting frequency array 
    sort(c1.begin(),c1.end());
    sort(c2.begin(),c2.end());

    for(int i=0;i<26;i++){
        if(c1[i]!=c2[i])
            return false;
    }
    return true;
    }
    
};
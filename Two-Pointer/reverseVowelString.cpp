class Solution {
public:
    string reverseVowels(string s) {

       string word = s;
       int n=s.size();
       int l=0,r =n-1;
       string vowel = "aeiouAEIOU";
       while(l<r){
        
        while(l<r && vowel.find(word[l])==string::npos){
            l++;
        }

        while(l<r && vowel.find(word[r])==string::npos){
            r--;
        }

        swap(word[l],word[r]);

        l++;
        r--;

       }
       return word;
    }
};
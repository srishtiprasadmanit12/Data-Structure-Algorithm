class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int>ans;
        vector<int>prefix(n+1,0);
        unordered_set<char>vowels = {'a','e','i','o','u'};
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i];
            if(vowels.count(words[i].front()) && vowels.count(words[i].back())){
                prefix[i+1]++;
            }
        }
        for(auto x:queries){
            int l = x[0];
            int r = x[1];
            ans.push_back(prefix[r+1]-prefix[l]);
        }
        return ans;
    }
};

/*
words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]
prefix = []
*/
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
    if (arr.empty()) return {}; // very imp to pass this solution
    //this is null check , if array is empty and we access those pointer/index in next step it will give error
    vector<int> dup = arr;
    sort(dup.begin(), dup.end());
    map<int, int> mp;
    
    mp[dup[0]] = 1;
    for (int i = 1; i < dup.size(); i++) {
        if (dup[i] > dup[i - 1]) {
            mp[dup[i]] = mp[dup[i - 1]] + 1;
        } else {
            mp[dup[i]] = mp[dup[i - 1]];
        }
    }
    
    vector<int> res;
    for (int x : arr) {
        res.push_back(mp[x]);
    }
    
    return res;    
    }
};
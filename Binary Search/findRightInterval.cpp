class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int>ans;
        map<int,int>mp{{INT_MAX,-1}};

        for(int i=0;i<intervals.size();i++){
            mp[intervals[i][0]] = i; //maintained index
        } 

        for(int i=0;i<intervals.size();i++){
            int endOfCurrentInterval = intervals[i][1];
            auto [key,value] = *mp.lower_bound(endOfCurrentInterval);
            // auto it = mp.lower_bound(endOfCurrentInterval)
            // ans.push_back(it->second)
            ans.push_back(value);
        }
        return ans;
    }
};
/*
   -2 -1 0 1 2 3 4 
              ---
           ---   
         ---
    Map to store indices of interval
    Sort 2d array

    [[3,4],[2,3],[1,2]] =====> [-1,0,1]

    [map]   1   2   3   4
    3 - 0
    2 - 1
    1 - 2 


    [[1,4],[2,3],[3,4]] ======> [-1,2,-1]

*/
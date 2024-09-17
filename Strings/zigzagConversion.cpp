class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1 || numRows >= s.length()){
            return s;
        }      
        int idx=0,d=1;
        vector<vector<char>>rows(numRows); 
        /*
        [   [],  // row 0
            [],  // row 1
            [],  // row 2
        ]
        */
        
        //iterate in given string
        for(char c : s){
            rows[idx].push_back(c);
            if(idx==0){
                d=1;
            }
            else if(idx == numRows - 1){
                d = -1;
            }
            idx += d;
        }

        //iterate in new 2d array
        string result;
        for(auto &row:rows){
            //row is an array in itself
            for(auto x:row){
                result+=x;
            }
        }
        return result;
    }
};
/*
  P   A    H    N  G
    A P  L S  I I
     y    i    r
*/
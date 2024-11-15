//Striver's approach
class Solution {
public:
    bool isSafe(int row,int col,vector<string>&curr,int n){
        int dupRow=row;
        int dupCol=col;
        //case- I
        while(row>=0 && col>=0){
            if(curr[row][col]=='Q'){
                return false;
            }
            row--;
            col--;
        }

        //case- II
        col = dupCol;
        row= dupRow;
        while(col>=0){
            if(curr[row][col]=='Q'){
                return false;
            }
            col--;
        }

        //case- III
        col=dupCol;
        row=dupRow;
        while(row<n && col>=0){
            if(curr[row][col]=='Q'){
                return false;
            }
            row++;
            col--;
        }

        return true;
    }
    void solve(int col,vector<string>&curr,vector<vector<string>>&ans,int n){
        if(col==n){
            ans.push_back(curr);
            return;
        }

        for(int row=0;row<n;row++){
            if(isSafe(row,col,curr,n)){
                curr[row][col]='Q';
                solve(col+1,curr,ans,n);
                curr[row][col]='.';   
            }
        }

    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>curr;
        string temp = "";
        for(int i=0;i<n;i++){
            temp+='.';
        }
        for(int i=0;i<n;i++){
            curr.push_back(temp);
        }
        solve(0,curr,ans,n);// 0th column
        return ans;
    }
};

/*

Initially
Temp---> '....'
Curr---> ['....','....','....','....']

Possible direction to check in isSafe() function is:
    \
     \ (row--,col--) case- I
<-----\ (col--) case-II
      /
     / (row++,col--) case-III
    /
*/
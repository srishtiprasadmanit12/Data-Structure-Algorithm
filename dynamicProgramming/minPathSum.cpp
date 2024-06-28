//RECURSION -> BASE CONDITION IS ALL U NEED TO FOCUS ON 
class Solution {
    public:
        int path(vector<vector<int>>& grid,int r,int c){
    
            if(r==0 && c==0)
                 return grid[0][0];
            if(r<0 || c<0)
                return 1000;
    
            int one = grid[r][c] + path(grid,r-1,c);
            int two = grid[r][c] + path(grid,r,c-1);
    
            return min(one,two);
        }
        int minPathSum(vector<vector<int>>& grid) {
           int r = grid.size();
           int c = grid[0].size();
    
           return path(grid,r-1,c-1); 
        }
    };

    //DYNAMIC PROGRAMMING - MEMOISATION APPROACH

  class Solution {
public:
    int path(vector<vector<int>>& grid,int r,int c,vector<vector<int>>&dp){

        if(r==0 && c==0){
            return grid[0][0];
        }
        if(r<0 || c<0)
            return INT_MAX;
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int one =INT_MAX,two=INT_MAX;
        if(r>0)
             one = grid[r][c] + path(grid,r-1,c,dp);
        if(c>0)
             two = grid[r][c] + path(grid,r,c-1,dp);

        return dp[r][c] = min(one,two);
    }
    int minPathSum(vector<vector<int>>& grid) {
       int r = grid.size();
       int c = grid[0].size();
       vector<vector<int>>dp(r,vector<int>(c,-1));
       return path(grid,r-1,c-1,dp); 
    }
};
    
    /*
    VISUALIZE QUESTION
    
    2,0  2,1  2,2
    1,0  1,1  1,2
    0,0  0,1  0,2
    
    */
    /*
    
            (2,0)
      1,0            2,1
    0,0 1,1         (2,2)  (1,1)
    0,1 0,1 1,2
    
    
    */
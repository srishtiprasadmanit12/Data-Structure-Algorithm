/*
Intuition
So, the intuition behind this problem is that we have to go through all the 1's from the border only that are present in the matrix.
So, I decided to do a simple dfs from the border of the matrix only

Approach
In order to approach this problem, I have done a simple dfs from the border of the matrix.
Firstly, I will make a visited matrix which we normally create while doing a graph problem.
Then I only traverse on borders of the matrix and see if I'll encounter a '1' which is not visited, then I'll mark it visited and also its neighbouring '1's visited because we can reach them from the border.
Same I will do in all the Four directions.
*/

class Solution {
public:
    void dfs(int i,int j,int r,int c,vector<vector<int>>&grid,vector<vector<int>>&vis){

        if(i<0 ||j<0||i==r||j==c || vis[i][j]||grid[i][j]==0){
            return;
        }
        vis[i][j]=1;

             dfs(i+1,j,r,c,grid,vis);
             dfs(i-1,j,r,c,grid,vis);
             dfs(i,j+1,r,c,grid,vis);
             dfs(i,j-1,r,c,grid,vis);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int r = grid.size();int c = grid[0].size();
        vector<vector<int>>vis(r,vector<int>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if((i==0||i==r-1||j==0||j==c-1)&&grid[i][j]==1){
                    dfs(i,j,r,c,grid,vis);
                }
            }
        }
        //After applying Dfs at boundary the cells which is left that is not visited & value of cell=1 we need to count that and return as answer
        int cnt=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j] == 1 && !vis[i][j])
                    cnt++;
            }
        }
        return cnt;
    }
};
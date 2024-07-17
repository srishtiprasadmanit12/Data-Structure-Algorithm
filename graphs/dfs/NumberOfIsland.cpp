class Solution {
  public:
    // Function to find the number of islands.
    
   void dfs(int i,int j,vector<vector<char>>& grid,int r,int c)
    {
        if(i<0 || j<0 ||i>=r || j>=c || grid[i][j]!='1')
            return;
        grid[i][j]='2';//visited
        dfs(i,j+1,grid,r,c);
        dfs(i,j-1,grid,r,c);
        dfs(i+1,j,grid,r,c);
        dfs(i-1,j,grid,r,c);
        dfs(i+1,j+1,grid,r,c);
        dfs(i-1,j+1,grid,r,c);
        dfs(i-1,j-1,grid,r,c);
        dfs(i+1,j-1,grid,r,c);
        
    }

    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        
        int island=0;
        int r=grid.size();
        int c=grid[0].size();
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(i,j,grid,r,c);
                    island++;
                }
                    
            }
       }
        return island;
    }
};
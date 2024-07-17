class Solution {
public:
    void check(vector<vector<int>>&grid,vector<vector<int>>&visited,int &count,int &flag,int i,int j){
        // Validity check
        if(i<0 || j<0 || j>grid[0].size()|| i>grid.size() || grid[i][j] == 0 || visited[i][j]){
            return;
        }
        // if the node is boundary node having value=1
        if(i==0 || j==0 || i == grid.size()-1 || j == grid[0].size()-1){
            flag = 1;
        }
        count+=1;
        visited[i][j]=1;

        check(grid,visited,count,flag,i-1,j);
        check(grid,visited,count,flag,i+1,j);
        check(grid,visited,count,flag,i,j-1);
        check(grid,visited,count,flag,i,j+1);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int count = 0;
        int ans = 0;

        int flag = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    int count = 0 , flag = 0;
                    check(grid,visited,count,flag,i,j);
                    if(flag==0){
                        ans+=count;
                    }
                }
            }
        }
        return ans;
    }
};
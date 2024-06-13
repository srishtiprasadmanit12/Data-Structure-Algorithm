class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       int n = grid.size();
       int m = grid[0].size();

       int tot_oranges = 0, rottenOranges=0;
       queue<pair<int,int>>q;
       //push all initial rotten oranges into queue  
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({i,j});
            }
            if(grid[i][j]!=0){
                tot_oranges++;
            }
        }
       }

       //Apply BFS to all elements in Queue

       int dx[4]={0,0,1,-1};
       int dy[4]={1,-1,0,0};

       int ans=0;
       while(!q.empty()){
            int k = q.size();
            rottenOranges+=k;
            while(k--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nx=x+dx[i],ny=y+dy[i];
                    if(nx<0 || ny<0 ||nx>=n ||ny>=m || grid[nx][ny]!=1){
                        continue;
                    }
                    grid[nx][ny]=2;
                    q.push({nx,ny});
                }

            }
            if(!q.empty()) ans++;
       }

       if(tot_oranges == rottenOranges) 
            return ans;
       else 
            return -1;

    }
};

/*
tot_oranges = total count of oranges
rottenOranges = count of rotten oranges
Queue = has all rotten oranges
*/
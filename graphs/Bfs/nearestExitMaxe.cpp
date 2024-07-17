class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        int ans = 0;
        queue<pair<int,int>>q;
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        //push initial position into queue
        q.push({entrance[0],entrance[1]});
         maze[entrance[0]][entrance[1]] = '+';
        while(!q.empty()){
            int k = q.size();
            ans++;

            while(k--){
                int x  = q.front().first;
                int y = q.front().second;
                    q.pop();
                for(int i=0;i<4;i++){
                    int nx = x+dx[i];
                    int ny = y+dy[i];
                    if(nx<0||ny<0||nx>=n||ny>=m|| maze[nx][ny]=='+') 
                        continue;
                    if((nx==0 || nx==n-1 || ny==0 || ny==m-1)&&(nx!=entrance[0] || ny!=entrance[1]))
                        return ans;
                    else{
                        maze[nx][ny]='+';// marking node as visited 
                        q.push({nx,ny});
                    }
                }
            }
        }
        return -1;
    }
};
/*
(1,2) -> (2,2)
2["+","+",".","+"]
1[".",".",".","+"]
0["+","+","+","."]
   0   1   2   3
*/
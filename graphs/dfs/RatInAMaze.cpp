void solve(int i,int j,string&str,int src,int dest,vector<vector<int>>&maze,vector<string>&res){
string temp;

if(i<0 || j<0 ||i>=maze.size()||j>=maze[0].size()||maze[i][j]==0){
   return; 
}

if(i==src && j==dest){
    res.push_back(temp);
    return;
}

maze[i][j]=2; // marking it visited

solve(i,j+1,str+"R",src,dest,maze,res);
solve(i+1,j,str+"U",src,dest,maze,res);
solve(i-1,j,str+"D",src,dest,maze,res);
solve(i,j-1,str+"L",src,dest,maze,res);

maze[i][j] = 1; // most imp step as we need to backtrack  

}

int main(){
vector<vector<int>>maze = {
    {1,0,0,0},
    {1,1,0,1},
    {0,1,0,0},
    {1,1,1,1}
}
int r = maze.size();
int c = maze[0].size();
int src = maze[0][0],dest = maze[r-1][c-1];
vector<string>res;
solve(0,0,"",src,dest,maze,res);
return res;
}
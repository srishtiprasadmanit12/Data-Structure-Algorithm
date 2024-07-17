class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int>adj[N];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int dis[N];
        for(int i=0;i<N;i++){
            dis[i]=INT_MAX;
        }
        dis[src]=0;
        queue<int>q;
        q.push(src);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto x:adj[node]){
                if(dis[x]>dis[node]+1) //initially dis[x]=intfinity
                dis[x]=dis[node]+1;
                q.push(x);
            }
        }
        vector<int>ans(N,-1);
        for(int i=0;i<N;i++){
            if(dis[i]!=INT_MAX)
                ans.push_back(dis[i]);
        }
        return ans;
    }
};
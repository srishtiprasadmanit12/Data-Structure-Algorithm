class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n + 1);
        for(auto& x : times){
            graph[x[0]].push_back({x[1], x[2]}); 
        }
        vector<int> dist(n + 1, INT_MAX);
        set<pair<int,int>>s;
        dist[k] = 0;
        s.insert({0, k});
        while(s.size()>0){
            auto node = *s.begin();
            int u  = node.second;
            int d = node.first;
            s.erase(s.begin());
            if(d > dist[u]) continue;
            for(auto& newnode : graph[u]){
                int v = newnode.first;
                int weight = newnode.second;
                if(dist[u] + weight < dist[v]){
                    dist[v] = dist[u] + weight;
                    s.insert({dist[v], v});
                }
            }
        }
        int ans = -1;
        for(int i = 1; i <= n; i++){
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans; 
    }
};
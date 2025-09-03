class Solution {
public:
    unordered_map<int,vector<pair<int,int>>> adj;
    long long mod = 1e9+7;
    void dijkstra(vector<int> &dist, int src) {
        dist[src] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,src});
        while(!pq.empty()) {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            for(auto &x : adj[node]) {
                int dest_node = x.first;
                int edge_weight = x.second;
                if(dis + edge_weight < dist[dest_node]) {
                    dist[dest_node] = dis + edge_weight;
                    pq.push({dist[dest_node], dest_node});
                }
            }
        }
    }

    long long dp[20001];
    long long dfs(int node, vector<int> &dist, int n) {
        if(node == n) {
            return 1;
        }
        if(dp[node] != -1) return dp[node];
        long long ans = 0;
        for(auto &[child,edge_weight] : adj[node]) {
            if(dist[node] > dist[child]) {
                ans = (ans + dfs(child, dist, n) % mod) % mod;
            }
        }
        return dp[node] = ans;
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<int> dist(n+1,INT_MAX);
        for(auto &edge : edges) {
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }
        dijkstra(dist, n);
        memset(dp,-1,sizeof(dp));
        return dfs(1,dist,n);
    }
};
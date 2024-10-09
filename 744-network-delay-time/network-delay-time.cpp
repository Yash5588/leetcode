class Solution {
public:
    vector<int> dijkstra(unordered_map<int,vector<pair<int,int>>> &adj, int n, int k) {
        vector<int> dist(n+1,INT_MAX);
        dist[0] = 0;
        dist[k] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> que;
        que.push({0,k});
        while(!que.empty()) {
            int node = que.top().second;
            int dis = que.top().first;
            que.pop();
            for(auto &x : adj[node]) {
                int dest_node = x.first;
                int edgeWeight = x.second;
                if(dis + edgeWeight < dist[dest_node]) {
                    dist[dest_node] = dis + edgeWeight;
                    que.push({dist[dest_node], dest_node});
                }
            }
        }
        return dist;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> adj;
        for(auto &x : times) {
            adj[x[0]].push_back({x[1],x[2]});
        }
        vector<int> dist = dijkstra(adj,n,k);
        int ma = INT_MIN;
        for(auto &x : dist) {
            ma = max(ma, x);
        }
        if(ma == INT_MAX) return -1;
        return ma;
    }
};
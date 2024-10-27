class Solution {
public:
    unordered_map<int,vector<pair<int,int>>> adj;
    void dijkstra(int src,vector<long long> &dist) {
        dist[src] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> que;
        que.push({0,src});
        while(!que.empty()) {
            int dis = que.top().first;
            int node = que.top().second;
            que.pop();
            for(auto &child : adj[node]) {
                int destNode = child.first;
                int edgeWeight = child.second;
                if(dis + edgeWeight < dist[destNode]) {
                    dist[destNode] = dis + edgeWeight;
                    que.push({dist[destNode],destNode});
                }
            }
        }
    }
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        for(auto &x : edges) {
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        vector<long long> sdist(n,INT_MAX);
        vector<long long> ddist(n,INT_MAX);
        dijkstra(0,sdist);
        dijkstra(n-1,ddist);
        int shortest_dist = sdist[n-1];
        vector<bool> ans(edges.size(),false);
        int index = 0;
        for(auto &x : edges) {
            long long u = x[0];
            long long v = x[1];
            long long weight = x[2];
            if(sdist[u] + weight + ddist[v] == shortest_dist) {
                ans[index] = true;
            }
            if(sdist[v] + weight + ddist[u] == shortest_dist) {
                ans[index] = true;
            }
            index++;
        }
        return ans;
    }
};
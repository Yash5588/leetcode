class Solution {
public:
    unordered_map<int,vector<pair<int,int>>> adj;
    int count_dijkstra(int src, int n, int threshold) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> que;
        que.push({0, src});
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
        int cnt = 0;
        for(int i = 0;i < n;i++) {
            if(dist[i] <= threshold && i != src) cnt++;
        }
        return cnt;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        for(auto &edge : edges) {
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }
        int mnm = INT_MAX;
        int city = 0;
        for(int i = 0;i < n;i++) {
            int cnt = count_dijkstra(i,n,distanceThreshold);
            if(mnm >= cnt) {
                mnm = cnt;
                city = i;
            }
        }
        return city;
    }
};
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int,int>>> adj;
        for(auto &x : flights) {
            adj[x[0]].push_back({x[1],x[2]});
        }
        queue<pair<int,int>> que;
        que.push({src,0});
        vector<int> distance(n,INT_MAX);
        distance[src] = 0;
        k++;
        while(k > 0 && !que.empty()) {
            int size = que.size();
            while(size--) {
                int node = que.front().first;
                int dis = que.front().second;
                que.pop();
                for(auto &x : adj[node]) {
                    int dest_node = x.first;
                    int edgeWeight = x.second;
                    if(dis + edgeWeight < distance[dest_node]) {
                        distance[dest_node] = dis + edgeWeight;
                        que.push({dest_node, dis + edgeWeight});
                    }
                }
            }
            k--;
        }
        if(distance[dst] == INT_MAX) return -1;
        return distance[dst];
    }
};
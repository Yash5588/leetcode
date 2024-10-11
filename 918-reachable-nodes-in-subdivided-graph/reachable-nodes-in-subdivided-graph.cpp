class Solution {
public:
    unordered_map<int, vector<pair<int,int>>> adj;
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        for(auto &x : edges) {
            adj[x[0]].push_back({x[1], x[2]+1});
            adj[x[1]].push_back({x[0], x[2]+1});
        }
        vector<int> distance(n,INT_MAX);
        distance[0] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> que;
        que.push({0,0});
        while(!que.empty()) {
            int dis = que.top()[0];
            int node = que.top()[1];
            que.pop();
            for(auto &it : adj[node]) {
                int dest_node = it.first;
                int edgeWeight = it.second;
                if(dis + edgeWeight < distance[dest_node]) {
                    distance[dest_node] = dis + edgeWeight;
                    que.push({distance[dest_node],dest_node});
                }
            }
        }
        int ans = 0;
        //check for  main nodes
        for(auto &x : distance) {
            if(x <= maxMoves) ans++; 
        }
        //for each edge check for sunbnodes based on shortest distance from source
        for(auto &x : edges) {
            int u = x[0];
            int v = x[1];
            int subnodes = x[2];
            //check if moves reach the node in first place
            //if they can't so 0
            //otherwise now check number of subnodes it can cover
            //from node u it covers dist[u] - moves right
            //it should not exceed subnodes so keep a check on that
            int a = (distance[u] > maxMoves) ? 0 : min(maxMoves - distance[u], subnodes);
            int b = (distance[v] > maxMoves) ? 0 : min(maxMoves - distance[v], subnodes);
            //get from u and v
            //then add another checker that this total subnodes should not exceed subnodes in that edge
            int totalCoveredSubNodes = min(a+b, subnodes);
            ans += totalCoveredSubNodes;
        }
        return ans;
    }
};
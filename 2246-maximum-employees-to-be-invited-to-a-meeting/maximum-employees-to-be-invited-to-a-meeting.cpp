class Solution {
public:
    unordered_map<int,vector<int>> adj;
    int BFS(int node, vector<bool> &visited) {
        int n = visited.size();
        queue<pair<int,int>> que;
        int maxDist = 0;
        que.push({node, 0});
        while(!que.empty()) {
            auto [currNode, dist] = que.front();
            maxDist = max(maxDist, dist);
            que.pop();

            for(auto &child : adj[currNode]) {
                if(!visited[child]) {
                    visited[child] = true;
                    que.push({child, dist+1});
                }
            }
        }
        return maxDist;
    }
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        for(int i = 0;i < n;i++) {
            int u = i;
            int v = favorite[i];
            adj[v].push_back(u);
        }

        int longestCycle = 0;
        int happyCouple = 0;

        vector<bool> visited(n, false);

        for(int i = 0;i < n;i++) {

            if(!visited[i]) {
                unordered_map<int,int> mp;

                int node = i;
                int nodeCount = 0;
                while(!visited[node]) {
                    visited[node] = true;
                    mp[node] = nodeCount;

                    int child = favorite[node];
                    nodeCount++;
                    if(mp.find(child) != mp.end()) {
                        int cycleLength = nodeCount - mp[child]; //we get length of cycle
                        longestCycle = max(longestCycle, cycleLength);
                        if(cycleLength == 2) {
                            vector<bool> visitedNodes(n, false);
                            visitedNodes[node] = true;
                            visitedNodes[child] = true;
                            happyCouple += 2 + BFS(node, visitedNodes) + BFS(child, visitedNodes);
                        }
                        break;
                    }
                    node = child;
                }
            }
        }
        return max(longestCycle, happyCouple);
    }
};
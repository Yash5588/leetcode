class Solution {
public:
    int bfs(vector<vector<int>> &graph) {
        set<pair<int,int>> visited;
        queue<pair<int,int>> que;
        int n = graph.size();
        for(int i = 0;i < n;i++) {
            que.push({i, 1 << i});
            visited.insert({i, 1 << i});
        }
        int level = 0;
        int destination = pow(2,n) - 1;
        while(!que.empty()) {
            int size = que.size();
            while(size--) {
                int node = que.front().first;
                int mask = que.front().second;
                que.pop();
                if(mask == destination) return level;
                for(auto &child : graph[node]) {
                    int new_mask = mask | (1 << child);
                    if(visited.find({child, new_mask}) == visited.end()) {
                        que.push({child, new_mask});
                        visited.insert({child,new_mask});
                    }
                }
            }
            level++;
        }
        return level;
    }
    int shortestPathLength(vector<vector<int>>& graph) {
        return  bfs(graph);
    }
};
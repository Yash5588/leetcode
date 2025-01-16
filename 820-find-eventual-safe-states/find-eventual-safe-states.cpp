
class Solution {
public:
    vector<int> topoSort(int n, unordered_map<int,vector<int>> &graph) {
        vector<int> indegree(n,0);
        for(int i = 0;i < n;i++) {
            for(auto &node : graph[i]) {
                indegree[node]++;
            }
        }

        queue<int> que;
        for(int i = 0;i < n;i++) {
            if(indegree[i] == 0) que.push(i);
        }

        vector<int> res;
        while(!que.empty()) {
            int curr = que.front();
            res.push_back(curr);
            que.pop();
            for(auto &child : graph[curr]) {
                indegree[child]--;
                if(indegree[child] == 0) que.push(child);
            }
        }
        return res;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int,vector<int>> adj;
        int n = graph.size();
        for(int i = 0;i < n;i++) {
            for(auto &node : graph[i]) {
                adj[node].push_back(i);
            }
        }
        vector<int> res = topoSort(n,adj);
        sort(res.begin(),res.end());
        return res;
    }
};
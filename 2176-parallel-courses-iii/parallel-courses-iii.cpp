class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int,vector<int>> adj;
        for(auto &x : relations) adj[x[0]].push_back(x[1]);
        vector<int> indegree(n+1,0);
        for(int i = 1;i <= n;i++) {
            for(auto &x : adj[i]) {
                indegree[x]++;
            }
        }
        queue<int> que;
        unordered_map<int,int> cost;
        for(int i = 1;i <= n;i++) {
            if(indegree[i] == 0) {
                cost[i] = time[i-1];
                que.push(i);
            }
        }
        int ma = INT_MIN;
        while(!que.empty()) {
            int node = que.front();
            que.pop();
            for(auto &child : adj[node]) {
                indegree[child]--;
                cost[child] = max(cost[child],cost[node]+time[child-1]);
                if(indegree[child] == 0) {
                    que.push(child);
                }
            }
        }
        for(int i = 1;i <= n;i++) {
            ma = max(ma, cost[i]);
        }
        return ma;
    }
};
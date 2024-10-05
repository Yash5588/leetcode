class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& pre) {
        vector<vector<int>> adj(V, vector<int> ());
        for(auto &x : pre) {
            adj[x[1]].push_back(x[0]);
        }
        vector<int> order;
        queue<int> que;
        vector<int> indegree(V,0);
        for(int i = 0;i < V;i++) {
            for(auto &x : adj[i]) {
                indegree[x]++;
            }
        }
        for(int i = 0;i < V;i++) {
            if(indegree[i] == 0) que.push(i);
        }
        while(!que.empty()) {
            int curr = que.front();
            order.push_back(curr);
            que.pop();
            for(auto &x : adj[curr]) {
                indegree[x]--;
                if(indegree[x] == 0)  que.push(x);
            }
        }
        if(order.size() == V) return order;
        return {};
    }
};
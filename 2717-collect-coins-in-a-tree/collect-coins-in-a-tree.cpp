class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();
        vector<set<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto &x : edges) {
            adj[x[0]].insert(x[1]);
            adj[x[1]].insert(x[0]);
            indegree[x[0]]++;
            indegree[x[1]]++;
        }
        queue<int> que;
        for(int i = 0;i < n;i++) {
            if(indegree[i] == 1 && coins[i] == 0) que.push(i);
        }
        int total = edges.size();
        int deleted = 0;
        while(!que.empty()) {
            int node = que.front();
            que.pop();
            for(auto &parent : adj[node]) {
                indegree[node]--;
                indegree[parent]--;
                deleted++;
                if(indegree[parent] == 1 && coins[parent] == 0) que.push(parent);
                adj[parent].erase(node);
                adj[node].erase(parent);
            }
        }
        for(int i = 0;i < n;i++) {
            if(indegree[i] == 1) que.push(i);
        }

        int dist = 2;
        while(dist--) {
            int size = que.size();
            while(size--) {
                int node = que.front();
                que.pop();
                for(auto &parent : adj[node]) {
                    indegree[parent]--;
                    indegree[node]--;
                    if(indegree[parent] == 1) que.push(parent);
                    deleted++;
                    adj[parent].erase(node);
                    adj[node].erase(parent);

                }
            }
        }
        return 2*(total-deleted);


    }
};
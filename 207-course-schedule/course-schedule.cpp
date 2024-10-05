class Solution {
public:
    bool isCycle(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &path_visited) {
        visited[node] = true;
        path_visited[node] = true;
        for(auto &child : adj[node]) {
            if(!visited[child]) {
                if(isCycle(child, adj, visited, path_visited)) return true;
            }
            else if(path_visited[child]) {
                return true;
            }
        }
        path_visited[node] = false;
        return false;
    }
    bool canFinish(int V, vector<vector<int>>& pre) {
        //graph conversion
        vector<vector<int>> adj(V, vector<int>());
        for(auto &x : pre) {
            adj[x[1]].push_back(x[0]);
        }
        queue<int> que;
        int c = 0;
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
            c++;
            que.pop();
            for(auto &x : adj[curr]) {
                indegree[x]--;
                if(indegree[x] == 0) que.push(x);
            }
        }
        return c == V;
    }
};
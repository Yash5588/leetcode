class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int size = trust.size();
        unordered_map<int,vector<int>> adj;
        for(auto &x : trust) {
            adj[x[0]].push_back(x[1]);
        }
        vector<int> indegree(n+1,0);
        for(int i = 1;i <= n;i++) {
            for(auto &x : adj[i]) {
                indegree[x]++;
            }
        }
        for(int i = 1;i <= n;i++) {
            if(indegree[i] == n-1 && adj[i].empty()) return i;
        }
        return -1;
    }
};
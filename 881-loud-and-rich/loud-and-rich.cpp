class Solution {
public:
    unordered_map<int,vector<int>> adj;
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        for(auto &x : richer) {
            adj[x[0]].push_back(x[1]);
        }
        vector<int> answer(n);
        for(int i = 0;i < n;i++) answer[i] = i;
        vector<int> indegree(n,0);
        for(int i = 0;i < n;i++) {
            for(auto &x : adj[i]) {
                indegree[x]++;
            }
        }
        queue<int> que;
        for(int i = 0;i < n;i++) {
            if(indegree[i] == 0) {
                que.push(i);
            }
        }
        while(!que.empty()) {
            int node = que.front();
            que.pop();
            for(auto &child : adj[node]) {
                if(quiet[answer[child]] > quiet[answer[node]]) {
                    answer[child] = answer[node];
                }
                indegree[child]--;
                if(indegree[child] == 0) que.push(child);
            }
        }
        return answer;
    }
};
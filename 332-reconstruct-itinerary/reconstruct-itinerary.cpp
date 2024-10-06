class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string> >> adj;
    int n = 0;
    void dfs(string node, vector<string> &path) {
        while(!adj[node].empty()) {
            string child = adj[node].top();
            adj[node].pop();
            dfs(child, path);
        }
        path.push_back(node);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        n = tickets.size();
        for(auto &x : tickets) {
            adj[x[0]].push(x[1]);
        }
        vector<string> path;
        dfs("JFK", path);
        reverse(path.begin(),path.end());
        return path;
    }
};
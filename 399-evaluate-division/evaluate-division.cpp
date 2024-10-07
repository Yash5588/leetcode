class Solution {
public:
    unordered_map<string, vector<pair<string,double>> > adj;
    double dfs(string &src, string &dst, unordered_map<string, bool> &visited) {
        visited[src] = true;
        if(src == dst) return 1;
        for(auto &x : adj[src]) {
            if(!visited[x.first]) {
                double prod = dfs(x.first, dst, visited);
                if(prod != 0) return x.second * prod;
            }
        }
        return 0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = values.size();
        for(int i = 0;i < n;i++) {
            adj[equations[i][0]].push_back({equations[i][0], 1});
            adj[equations[i][1]].push_back({equations[i][1], 1});
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], 1/values[i]});
        }
        vector<double> res;
        for(auto &q : queries) {
            string src = q[0];
            string dst = q[1];
            unordered_map<string,bool> visited;
            if(adj.find(src) != adj.end()) {
                double ans = dfs(src, dst, visited);
                if(ans == 0) res.push_back(-1);
                else res.push_back(ans);
                cout << src << endl;
            }
            else res.push_back(-1);
        }
        return res;
    }
};
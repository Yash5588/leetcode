class Solution {
public:
    unordered_map<int,vector<int>> adj;
    unordered_map<int,bool> visited;
    bool dfs(int node, int cnt, unordered_set<int> &even, unordered_set<int> &odd) {
        if(cnt & 1) odd.insert(node);
        else even.insert(node);
        visited[node] = true;
        for(auto &child : adj[node]) {
            if(cnt & 1) {
                if(odd.find(child) != odd.end()) return false;
                else if(even.find(child) == even.end()) {
                    if(!dfs(child, cnt+1,even, odd)) return false;
                }
            }
            else {
                if(even.find(child) != even.end()) return false;
                else if(odd.find(child) == odd.end()) {
                    if(!dfs(child, cnt+1, even, odd)) return false;
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        for(auto &x : dislikes) {
            adj[x[0]].push_back(x[1]);
        }
        int cnt = 0;
        bool flag = true;
        for(int i = 1;i <= n;i++) {
            if(!visited[i]) {
                unordered_set<int> even,odd;
                flag &= dfs(i, 0, even, odd);
                if(!flag) return false;
            }
        }
        return true;
    }
};
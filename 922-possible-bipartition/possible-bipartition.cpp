class Solution {
public:
    unordered_map<int,vector<int>> adj;
    set<int> even;
    set<int> odd;
    int maxCnt = 0;
    bool dfs(int node, int cnt) {
        if(cnt & 1) odd.insert(node);
        else even.insert(node);
        for(auto &child : adj[node]) {
            if(cnt & 1) {
                if(odd.find(child) != odd.end()) return false;
                else if(even.find(child) == even.end()) {
                    if(!dfs(child, cnt+1)) return false;
                }
            }
            else {
                if(even.find(child) != even.end()) return false;
                else if(odd.find(child) == odd.end()) {
                    if(!dfs(child, cnt+1)) return false;
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
            if(even.count(i) == 0 && odd.count(i) == 0) {
                flag &= dfs(i, 0);
                even.clear();
                odd.clear();
                if(!flag) return false;
            }
        }
        return true;
    }
};
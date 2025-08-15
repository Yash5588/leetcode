class Solution {
public:
    unordered_map<int,vector<int>> adj;
    int mxm = 1;
    int dfs(int node, string &s) {
        int first = 0;
        int second = 0;
        for(int child : adj[node]) {
            int len = dfs(child, s);
            if(s[child] != s[node]) {
                if(first <= len) {
                    second = first;
                    first = len;
                }
                else if(second <= len) {
                    second = len;
                }
            }
        }
        mxm = max(mxm, 1 + first + second);
        return first+1;

    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        for(int i = 0;i < n;i++) {
            adj[parent[i]].push_back(i);
        }
        dfs(0, s);
        return mxm;
    }
};
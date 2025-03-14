class Solution {
public:
    unordered_map<int,vector<int>> adj;
    int topoSort(int n, string &colors) {
        vector<int> degree(n,0);
        for(int i = 0;i < n;i++) {
            for(auto &child : adj[i]) {
                degree[child]++;
            }
        }
        queue<int> que;

        int mxm = INT_MIN;
        int cnt = 0;
        vector<vector<int>> freq_dp(n, vector<int> (26,0));

        for(int i = 0;i < n;i++) {
            if(degree[i] == 0) {
                que.push(i);
            } 
        }


        while(!que.empty()) {

            int node = que.front();
            que.pop();

            int idx = colors[node] - 'a';
            freq_dp[node][idx]++;

            mxm = max(mxm, freq_dp[node][idx]);

            cnt++;

            for(auto &child : adj[node]) {


                for(int i = 0;i < 26;i++) {
                    freq_dp[child][i] = max(freq_dp[child][i], freq_dp[node][i]);
                }

                degree[child]--;
                if(degree[child] == 0) {
                    que.push(child);
                }
            }
        }
        if(cnt != n) return -1;
        return mxm;
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        for(auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        int n = colors.size();
        return topoSort(n,colors);
    }
};
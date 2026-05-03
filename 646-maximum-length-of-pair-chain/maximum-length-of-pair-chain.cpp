class Solution {
public:
    int dp[1000][1000];
    int solve(vector<vector<int>> &pairs, int idx, int prev) {
        int n = pairs.size();
        if(idx >= n) return 0;
        if(dp[idx][prev] != -1) return dp[idx][prev];
        int pick = 0, not_pick = 0;
        if(prev == n || pairs[prev][1] < pairs[idx][0]) {
            pick = 1 + solve(pairs, idx+1, idx);
        }
        not_pick = solve(pairs, idx+1, prev);
        return dp[idx][prev] = max(pick, not_pick);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        memset(dp,-1,sizeof(dp));
        return solve(pairs, 0, pairs.size());
    }
};
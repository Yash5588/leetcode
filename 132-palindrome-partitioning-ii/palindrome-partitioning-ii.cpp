class Solution {
public:
    int dp[2000];
    int pal_dp[2000][2000];
    int solve(string &s, int idx) {
        int n = s.length();
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];
        int mnm = 1e5;
        for(int i = idx;i < n;i++) {
            if(isPal(s, idx, i)) {
                mnm = min(mnm, 1 + solve(s, i+1));
            }
        }
        return dp[idx] = mnm;
    }
    bool isPal(string &s, int start, int end) {
        if(start >= end) return true;
        if(pal_dp[start][end] != -1) return pal_dp[start][end];
        if(s[start] == s[end]) {
            return pal_dp[start][end] = isPal(s, start+1, end-1);
        }
        return pal_dp[start][end] = false;
    }
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        memset(pal_dp, -1,sizeof(pal_dp));
        return solve(s,0)-1;
    }
};
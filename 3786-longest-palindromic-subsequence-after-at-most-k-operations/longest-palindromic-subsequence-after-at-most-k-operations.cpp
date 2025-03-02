class Solution {
public:
    int dp[201][201][201];
    int solve(string &s, int i, int j,int k) {
        int n = s.length();
        if(i > j) return 0;
        if(i == j) return 1;
        if(dp[i][j][k] != -1) return dp[i][j][k];
        if(s[i] == s[j]) {
            return dp[i][j][k] = 2 + solve(s, i+1, j-1,k);
        }
        int skip1 = solve(s, i+1, j, k);
        int skip2 = solve(s, i, j-1, k);
        int change = INT_MIN;
        if(k > 0) {
            int diff = abs(s[i] - s[j]);
            int ops = min(diff, 26-diff);
            if(ops <= k) {
                change = 2 + solve(s, i+1, j-1, k - ops);
            }
        }
        return dp[i][j][k] = max({skip1, skip2, change});
    }
    int longestPalindromicSubsequence(string s, int k) {
        int n = s.length();
        memset(dp,-1,sizeof(dp));
        return solve(s,0,n-1,k);
    }
};
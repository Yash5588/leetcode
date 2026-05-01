class Solution {
public:
    int dp[1000][1000];
    int solve(string &s, string &t, int idx1, int idx2) {
        int n1 = s.length();
        int n2 = t.length();
        if(idx2 >= n2) return 1;
        if(idx1 >= n1) return 0;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        if(s[idx1] == t[idx2]) {
            return dp[idx1][idx2] = solve(s,t,idx1+1,idx2+1) + solve(s,t,idx1+1, idx2);
        }
        return dp[idx1][idx2] = solve(s,t,idx1+1,idx2);
    }
    int numDistinct(string s, string t) {
        if(s.length() < t.length()) return 0;
        memset(dp,-1,sizeof(dp));
        return solve(s, t, 0, 0);
    }
};
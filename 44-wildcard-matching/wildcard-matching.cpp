class Solution {
public:
    int dp[2000][2000];
    bool solve(string &s, string &p,  int i, int j) {
        int n1 = s.length();
        int n2 = p.length();
        if(i >= n1 && j >= n2) return true;
        if(j >= n2) return false;
        if(i >= n1) {
            while(j < n2 && p[j] == '*') j++;
            return j >= n2;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = solve(s, p, i+1, j+1);
        }
        if(p[j] == '*') {
            return dp[i][j] = solve(s, p, i+1, j) || solve(s, p, i+1, j+1) || solve(s, p, i, j+1);
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        memset(dp,-1,sizeof(dp));
        return solve(s, p, 0, 0);
    }
};
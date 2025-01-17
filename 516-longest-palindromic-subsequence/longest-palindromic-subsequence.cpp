class Solution {
public:
    int dp[1001][1001];
    int solve(string &s1 ,string &s2, int pos1, int pos2) {
        int n = s1.length();
        if(pos1 >= n || pos2 >= n) return 0;
        int ma = INT_MIN;
        if(dp[pos1][pos2] != -1) return dp[pos1][pos2];
        if(s1[pos1] == s2[pos2]) {
            return dp[pos1][pos2] = 1 + solve(s1, s2, pos1+1, pos2+1);
        }
        return dp[pos1][pos2] = max(solve(s1, s2, pos1+1, pos2), solve(s1, s2, pos1, pos2+1));
    }
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s.begin(),s.end());
        memset(dp,-1,sizeof(dp));
        return solve(s,s2,0,0);
    }
};
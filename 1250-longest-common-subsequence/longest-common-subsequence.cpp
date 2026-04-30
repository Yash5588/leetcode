class Solution {
public:
    int dp[1000][1000];
    int solve(string &str1, string &str2, int idx1, int idx2) {
        int n1 = str1.length();
        int n2 = str2.length();
        if(idx1 >= n1 || idx2 >= n2) return 0;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        int pick = 0, not_pick = 0;
        if(str1[idx1] == str2[idx2]) {
            pick = 1 + solve(str1, str2, idx1+1, idx2+1);
        }
        not_pick = max(solve(str1, str2, idx1+1, idx2), solve(str1, str2, idx1, idx2+1));
        return dp[idx1][idx2] = max(pick, not_pick);
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return solve(text1, text2, 0, 0);
    }
};
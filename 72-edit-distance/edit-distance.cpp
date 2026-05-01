class Solution {
public:
    int dp[500][500];
    int solve(string &str1, string &str2, int idx1, int idx2) {
        int n1 = str1.length();
        int n2 = str2.length();
        if(idx1 >= n1 && idx2 >= n2) {
            return 0;
        }
        if(idx1 >= n1) {
            return n2 - idx2;
        }
        if(idx2 >= n2) {
            return n1 - idx1;
        }
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        if(str1[idx1] == str2[idx2]) {
            return dp[idx1][idx2] = solve(str1, str2, idx1+1, idx2+1);
        }
        int insert = 1 + solve(str1, str2, idx1, idx2+1);
        int deleted = 1 + solve(str1, str2, idx1+1, idx2);
        int replace = 1 + solve(str1, str2, idx1+1, idx2+1);
        return dp[idx1][idx2] = min({insert, deleted, replace});
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return solve(word1, word2, 0, 0);
    }
};
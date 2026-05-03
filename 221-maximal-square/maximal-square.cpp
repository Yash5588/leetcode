class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        int mxm = INT_MIN;
        for(int i = 1;i <= m;i++) {
            for(int j = 1;j <= n;j++) {
                if(matrix[i-1][j-1] == '1') {
                    dp[i][j] = (matrix[i-1][j-1]-'0') + min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]});
                }
                mxm = max(mxm, dp[i][j]);
            }
        }
        return mxm*mxm;
    }
};
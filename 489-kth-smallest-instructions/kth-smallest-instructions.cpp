class Solution {
public:
    int dp[16][16];
    int allPathsCount(int n, int m, int row, int col) {
        if(row >= n || col >= m) return 0;
        if(row == n-1 && col == m-1) return 1;
        if(dp[row][col] != -1) return dp[row][col];
        return dp[row][col] = allPathsCount(n,m,row+1,col) + allPathsCount(n,m,row,col+1);
    }
    string kthSmallestPath(vector<int>& dest, int k) {
        int n = dest[0] + 1;
        int m = dest[1] + 1;
        memset(dp,-1,sizeof(dp));
        allPathsCount(n,m,0,0);
        int row = 0,col = 0;
        string ans;
        while(row < n-1 && col < m-1 && k > 0) {
            if(k <= dp[row][col+1]) {
                ans += 'H';
                col++;
            }
            else {
                ans += 'V';
                k -= dp[row][col+1]; //exclude all horizontal paths
                row++;                    // consider paths which starts with V
            }
        }
        while(row < n-1) {
            ans += 'V';
            row++;
        }
        while(col < m-1) {
            ans += 'H';
            col++;
        }
        return ans;
    }
};
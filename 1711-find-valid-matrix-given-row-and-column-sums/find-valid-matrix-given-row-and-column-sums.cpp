class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rsum, vector<int>& csum) {
        int n = rsum.size();
        int m = csum.size();
        vector<vector<int>> grid(n, vector<int> (m,0));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                grid[i][j] = min(rsum[i],csum[j]);
                rsum[i] -= grid[i][j];
                csum[j] -= grid[i][j];
            }
        }
        return grid;
    }
};
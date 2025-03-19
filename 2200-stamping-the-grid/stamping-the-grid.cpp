class Solution {
public:
    int getSum(int x1, int y1, int x2, int y2, vector<vector<int>> &prefix) {
        x1++;
        y1++;
        x2++;
        y2++;
        return prefix[x2][y2] - prefix[x1-1][y2] - prefix[x2][y1-1] + prefix[x1-1][y1-1]; 
    }
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int m = grid.size();
        int n = grid[0].size();
        int sh = stampHeight;
        int sw = stampWidth;
        vector<vector<int>> prefix(m+1, vector<int> (n+1,0));
        //store prefix sum for check if we can fit a stamp
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                prefix[i+1][j+1] = grid[i][j] + prefix[i+1][j] + prefix[i][j+1] - prefix[i][j];
            }
        }


        vector<vector<int>> diff(m+2, vector<int> (n+2,0));
        for(int i = 0; i < m - sh + 1; i++) {
            for(int j = 0; j < n - sw + 1;j++) {
                if(getSum(i, j, i+sh-1, j+sw-1, prefix) == 0) {
                    diff[i+1][j+1] += 1;
                    diff[i+sh+1][j+sw+1] += 1;
                    diff[i+sh+1][j+1] -= 1;
                    diff[i+1][j+sw+1] -= 1;
                }
            }
        }

        //now propagate diff array
        for(int i = 1;i <= m;i++) {
            for(int j = 1;j <= n;j++) {
                diff[i][j] += (diff[i-1][j] + diff[i][j-1] - diff[i-1][j-1]); 
            }
        }

        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(grid[i][j] == 0 && diff[i+1][j+1] == 0) return false;
            }
        }
        return true;
    }
};
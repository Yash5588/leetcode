class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        map<int,priority_queue<int,vector<int>,greater<int>>> negative;
        map<int,priority_queue<int>> positive;
        int n = grid.size();
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                if(i - j < 0) {
                    negative[i-j].push(grid[i][j]);
                }
                else {
                    positive[i-j].push(grid[i][j]);
                }
            }
        } 
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                if(i - j < 0) {
                    grid[i][j] = negative[i-j].top();
                    negative[i-j].pop();
                }
                else {
                    grid[i][j] = positive[i-j].top();
                    positive[i-j].pop();
                }
            }
        }
        return grid;
    }
};
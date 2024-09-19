class Solution {
public:
    vector<pair<int,int>> adj = {{-1,0},{0,-1},{0,1},{1,0}};
    void bfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int mid, int row, int col) {
        int n = grid.size();
        queue<pair<int,int>> que;
        if(grid[0][0] <= mid) {
            que.push({0,0});
            visited[0][0] = true;
        }
        while(!que.empty()) {
            int curr_row = que.front().first;
            int curr_col = que.front().second;
            que.pop();
            for(int i = 0;i < 4;i++) {
                int new_row = curr_row + adj[i].first;
                int new_col = curr_col + adj[i].second;
                if(new_row >= 0 && new_row < n && new_col >= 0 && new_col < n) {
                    if(!visited[new_row][new_col] && grid[new_row][new_col] <= mid) {
                        visited[new_row][new_col] = true;
                        que.push({new_row,new_col});
                    }
                }
            }
        }
        
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int low = 0,high = n*n - 1;
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            vector<vector<bool>> visited(n,vector<bool> (n,false));
            bfs(grid,visited,mid,0,0);
            if(visited[n-1][n-1]) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
            visited.clear();
        }
        return ans;
    }
};
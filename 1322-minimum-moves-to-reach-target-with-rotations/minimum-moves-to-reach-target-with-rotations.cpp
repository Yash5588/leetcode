class Solution {
public:
    vector<vector<int>> horizon = {{0,1,0,1}, {1,0,1,0}, {0,0,1,-1}};
    vector<vector<int>> verti = {{0,1,0,1}, {1,0,1,0}, {0,0,-1,1}};
    int bfs(vector<vector<int>> &grid) {
        int n = grid.size();
        queue<vector<int>> que;
        map<vector<int>, bool> visited;
        que.push({0,0,0,1,0});
        visited[{0,0,0,1}] = true;
        int c = 0;
        while(!que.empty()) {
            vector<int> curr = que.front();
            que.pop();
            int tail_row = curr[0];
            int tail_col = curr[1];
            int head_row = curr[2];
            int head_col = curr[3];
            int cnt = curr[4];
            cout << head_row << ' ' << head_col << ' ' << tail_row << ' ' << tail_col << endl;
            cout << cnt << endl;
            if(tail_row == n-1 && tail_col == n-2 && head_row == n-1 && head_col == n-1) {
                return cnt;
            }
            if(tail_row == head_row) {
                for(int i = 0;i < 3;i++) {
                    int t_row = tail_row + horizon[i][0];
                    int t_col = tail_col + horizon[i][1];
                    int h_row = head_row + horizon[i][2];
                    int h_col = head_col + horizon[i][3];
                    if(h_row >= 0 && h_row < n && h_col >= 0 && h_col < n) {
                        if(grid[h_row][h_col] == 0 && grid[t_row][t_col] == 0 && !visited[{t_row,t_col,h_row,h_col}]) {
                            if(i != 2) {
                                que.push({t_row,t_col,h_row,h_col,cnt+1});
                                visited[{t_row,t_col,h_row,h_col}] = true;
                            }
                            else {
                                if(grid[t_row+1][t_col+1] == 0) {
                                    que.push({t_row,t_col,h_row,h_col,cnt+1});
                                    visited[{t_row,t_col,h_row,h_col}] = true;
                                }
                            }
                        }
                    }
                }
            }
            else {
                for(int i = 0;i < 3;i++) {
                    int t_row = tail_row + verti[i][0];
                    int t_col = tail_col + verti[i][1];
                    int h_row = head_row + verti[i][2];
                    int h_col = head_col + verti[i][3];
                    if(h_row >= 0 && h_row < n && h_col >= 0 && h_col < n) {
                        if(grid[t_row][t_col] == 0 && grid[h_row][h_col] == 0 && !visited[{t_row,t_col,h_row,h_col}]) {
                            if(i != 2) {
                                que.push({t_row,t_col,h_row,h_col,cnt+1});
                                visited[{t_row,t_col,h_row,h_col}] = true;
                            }
                            else {
                                if(grid[t_row+1][t_col+1] == 0) {
                                    que.push({t_row,t_col,h_row,h_col,cnt+1});
                                    visited[{t_row,t_col,h_row,h_col}] = true;
                                }
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
    int minimumMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        return bfs(grid);
    }
};
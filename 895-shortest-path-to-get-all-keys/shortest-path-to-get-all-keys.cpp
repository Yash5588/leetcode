class Solution {
public:
    vector<pair<int,int>> adj = {{-1,0},{0,-1},{0,1},{1,0}};
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int keys = 0;
        pair<int, int> start_point = {-1, -1};

        // Count the total number of keys and find the starting point.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] >= 'a' && grid[i][j] <= 'f') keys++;
                if (grid[i][j] == '@') start_point = {i, j};
            }
        }

        queue<vector<int>> que;
        que.push({start_point.first, start_point.second, 0, 0});
        int status_size = pow(2, keys);
        int visited[status_size][m][n];
        memset(visited, 0, sizeof(visited));
        visited[0][start_point.first][start_point.second] = 1;

        while (!que.empty()) {
            int row = que.front()[0];
            int col = que.front()[1];
            int moves = que.front()[2];
            int status = que.front()[3];
            que.pop();

            // Check if we have collected all keys
            if (status == (1 << keys) - 1) return moves;

            for (int i = 0; i < 4; i++) {
                int new_row = row + adj[i].first;
                int new_col = col + adj[i].second;

                if (new_row >= 0 && new_row < m && new_col >= 0 && new_col < n) {
                    char cell = grid[new_row][new_col];
                    int new_status = status;

                    if (cell == '#') continue;

                    if (cell >= 'a' && cell <= 'f') {
                        new_status |= (1 << (cell - 'a'));
                    }

                    if (cell >= 'A' && cell <= 'F') {
                        if (!(status & (1 << (cell - 'A')))) continue; 
                    }

                    if (!visited[new_status][new_row][new_col]) {
                        que.push({new_row, new_col, moves + 1, new_status});
                        visited[new_status][new_row][new_col] = 1;
                    }
                }
            }
        }
        return -1; 
    }
};

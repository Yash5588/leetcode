class Solution {
public:
    priority_queue<int, vector<int>, greater<int>> p_que;
    unordered_map<int, pair<int,int>> coordinates;
    vector<pair<int,int>> adj = {{-1,0},{0,-1},{0,1},{1,0}};
    int bfs(int row, int col,int target, vector<vector<int>> &forest, vector<vector<bool>> &visited) {
        int m = forest.size();
        int n = forest[0].size();
        int t_row = coordinates[target].first;
        int t_col = coordinates[target].second;
        queue<pair<int,int>> que;
        if(forest[row][col] != 0) que.push({row,col});
        int level = 0;
        while(!que.empty()) {
            int size = que.size();
            while(size--) {
                int curr_row = que.front().first;
                int curr_col = que.front().second;
                que.pop();
                if(visited[curr_row][curr_col]) continue;
                if(curr_row == t_row && curr_col == t_col) return level;
                visited[curr_row][curr_col] = true;
                for(int i = 0;i < 4;i++) {
                    int n_row = curr_row + adj[i].first;
                    int n_col = curr_col + adj[i].second;
                    if(n_row >= 0 && n_row < m && n_col >= 0 && n_col < n) {
                        if(forest[n_row][n_col] != 0 && !visited[n_row][n_col]) {
                            que.push({n_row,n_col});
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size();
        int n = forest[0].size();
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(forest[i][j] > 1) {
                    coordinates[forest[i][j]] = {i,j};
                    p_que.push(forest[i][j]);
                }
            }
        }
        int prev_row = 0,prev_col = 0;
        int score = 0;
        while(!p_que.empty()) {
            int curr = p_que.top();
            p_que.pop();
            vector<vector<bool>> visited(m, vector<bool>(n,false)); 
            // if(curr == 3) {
            //     for(int i = 0;i < m;i++) {
            //         for(int j = 0;j < n;j++) {
            //             cout << visited[i][j] << ' ';
            //         }
            //         cout << endl;
            //     }
            // }
            int cnt = bfs(prev_row, prev_col, curr, forest, visited);
            if(cnt == -1) return -1;
            prev_row = coordinates[curr].first;
            prev_col = coordinates[curr].second;
            score += cnt;
        }
        return score;
    }
};
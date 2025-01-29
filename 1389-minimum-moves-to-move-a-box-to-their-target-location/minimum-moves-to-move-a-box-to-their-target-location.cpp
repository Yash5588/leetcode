class Solution {
public:
    vector<pair<int,int>> adj = {{-1,0},{1,0},{0,1},{0,-1}};

    //current box position is also an obstacle
    bool canReach(vector<vector<char>>& grid, int start_row, int start_col, int target_row, int target_col, int curr_box_row, int curr_box_col) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> que;
        vector<vector<bool>> visited(m, vector<bool> (n,false));
        que.push({start_row, start_col});
        while(!que.empty()) {
            int row = que.front().first;
            int col = que.front().second;
            que.pop();
            if(visited[row][col]) continue;
            if(target_row == row && target_col == col) return true;
            visited[row][col] = true;
            for(int i = 0;i < 4;i++) {
                int n_row = row + adj[i].first;
                int n_col = col + adj[i].second;
                if(n_row >= 0 && n_row < m && n_col >= 0 && n_col < n && grid[n_row][n_col] == '.') {
                    //current box position is also an obstacle
                    if(!(n_row == curr_box_row && n_col == curr_box_col)) {
                        que.push({n_row, n_col});
                    }
                }
            }
        }
        return false;
    }
    int minPushBox(vector<vector<char>>& grid) {
        //get all the coordinates
        int m = grid.size();
        int n = grid[0].size();
        vector<int> initial_player;
        vector<int> initial_box;
        vector<int> target;
        //after loading coordinates make sure that we are marking them as '.'
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(grid[i][j] == 'S') {
                    initial_player = {i,j};
                    grid[i][j] = '.';
                }
                if(grid[i][j] == 'B') {
                    initial_box = {i,j};
                    grid[i][j] = '.';
                }
                if(grid[i][j] == 'T') {
                    target = {i,j};
                    grid[i][j] = '.';
                }
            }
        }
        //keep track of current state
        set<tuple<int,int,int,int>> visited;
        queue<vector<int>> que;
        que.push({initial_box[0],initial_box[1],initial_player[0],initial_player[1],0});
        //<box_row, box_col, pushes>
        while(!que.empty()) {
            int box_row = que.front()[0];
            int box_col = que.front()[1];
            int player_row = que.front()[2];
            int player_col = que.front()[3];
            int pushes = que.front()[4];
            que.pop();
            if(visited.find({box_row, box_col, player_row, player_col}) != visited.end()) continue;

            if(box_row == target[0] && box_col == target[1]) return pushes;

            visited.insert({box_row, box_col, player_row, player_col});

            for(int i = 0;i < 4;i++) {
                //if we want box to move right then person has to be in box's left right
                //so we will be checking can the person reach box left position
                int new_box_row = box_row + adj[i].first;
                int new_box_col = box_col + adj[i].second;
                int player_target_row = box_row - adj[i].first;
                int player_target_col = box_col - adj[i].second;
                
                //check both new positon of box and target position of player valid or not
                if(new_box_row >= 0 && new_box_row < m && new_box_col >= 0 && new_box_col < n) {
                    if(player_target_row >= 0 && player_target_row < m && player_target_col >= 0 && player_target_col < n) {
                        //check if both positions are free cells not walls
                        if(grid[new_box_row][new_box_col] == '.' && grid[player_target_row][player_target_col] == '.') {
                            //now check whether the player can from  his previous position to target position so that the box can move in specific direction
                            //ex: if box is at (2,3) and it wants to move to (2,2) now what should be player position?
                            //yes it should be at (2,1) then only he can push to (2,3)
                            //so check if player can reach (2,1) from his current position
                            //also make sure current box position is treated as obstacle 
                            if(canReach(grid, player_row, player_col, player_target_row, player_target_col, box_row, box_col)) {
                                que.push({new_box_row, new_box_col, box_row, box_col, pushes+1});
                            }
                        }
                    }
                }

            }
        }
        return -1;
    }
};
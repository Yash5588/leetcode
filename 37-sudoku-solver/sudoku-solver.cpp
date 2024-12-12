class Solution {
public:
    vector<unordered_set<char>> rows, cols, grids;
    bool solved = false; 
    
    bool isSafe(vector<vector<char>>& board, char ch, int i, int j) {
        if (rows[i].find(ch) != rows[i].end()) return false;
        if (cols[j].find(ch) != cols[j].end()) return false;
        int row = i / 3, col = j / 3;
        int grid_idx = 3 * row + col;
        if (grids[grid_idx].find(ch) != grids[grid_idx].end()) return false;
        return true;
    }
    
    bool solve(vector<vector<char>>& board, int i, int j) {

        //all rows have been completed
        if (i >= 9) {
            return true;
        }

        //go to next row if current row completed
        if (j >= 9) {
            return solve(board, i + 1, 0);
        }
        //skip the particular cell and go to next cell
        if (board[i][j] != '.') { 
            return solve(board, i, j + 1);
        }
        
        for (char ch = '1'; ch <= '9'; ch++) {
            if (isSafe(board, ch, i, j)) {
                int row = i / 3, col = j / 3;
                int grid_idx = 3 * row + col;
                board[i][j] = ch;
                rows[i].insert(ch);
                cols[j].insert(ch);
                grids[grid_idx].insert(ch);
                
                if(solve(board, i, j + 1)) return true;
                
                board[i][j] = '.';
                rows[i].erase(ch);
                cols[j].erase(ch);
                grids[grid_idx].erase(ch);
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        rows.resize(9);
        cols.resize(9);
        grids.resize(9);
        
        // Initialize the sets with pre-filled values
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    rows[i].insert(board[i][j]);
                    cols[j].insert(board[i][j]);
                    int row = i / 3, col = j / 3;
                    int grid_idx = 3 * row + col;
                    grids[grid_idx].insert(board[i][j]);
                }
            }
        }
        
        solve(board, 0, 0);
    }
};

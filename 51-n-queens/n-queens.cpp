class Solution {
public:
    vector<string> board;
    bool isSafe(int n, int row, int col) {
        //top
        for(int i = row;i >= 0;i--) {
            if(board[i][col] == 'Q') return false;
        }
        //left
        for(int j = col;j >= 0;j--) {
            if(board[row][j] == 'Q') return false;
        }
        //upper left diagonal
        for(int i = row,j = col;i >= 0 && j >= 0;i--,j--) {
            if(board[i][j] == 'Q') return false;
        }
        //upper right diagonal
        for(int i = row,j = col;i >= 0 && j < n;i--,j++) {
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }
    vector<vector<string>> res;
    void solve(int n, int row) {
        if(row >= n) {
            res.push_back(board);
            return;
        }
        for(int col = 0;col < n;col++) {
            if(isSafe(n,row,col)) {
                board[row][col] = 'Q';
                solve(n, row+1);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string s;
        for(int i = 0;i < n;i++) {
            s += '.';
        }
        board.resize(n,s);
        solve(n,0);
        return res;
    }
};
class Solution {
public:
    bool isSafe(vector<vector<bool>> &board, int row, int col) {
        int n = board.size();
        for(int i = row;i >= 0;i--) {
            if(board[i][col] == true) return false;
        }
        for(int i = row,j = col;i >= 0 && j >= 0;i--,j--) {
            if(board[i][j] == true) return false;
        }
        for(int i = row,j = col;i >= 0 && j < n;i--,j++) {
            if(board[i][j] == true) return false;
        }
        return true;
    }
    int solve(vector<vector<bool>> &board, int row) {
        int n = board.size();
        if(row >= n) return 1;
        int cnt = 0;
        for(int col = 0;col < n;col++) {
            if(isSafe(board,row,col)) {
                board[row][col] = true;
                cnt += solve(board,row+1);
                board[row][col] = false;
            }
        }
        return cnt;
    }
    int totalNQueens(int n) {
        vector<vector<bool>> board(n,vector<bool> (n,false));
        return solve(board,0);
    }
};
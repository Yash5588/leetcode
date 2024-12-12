class Solution {
public:
    vector<pair<int,int>> adj = {{0,-1},{-1,0},{0,1},{1,0}};
    bool solve(vector<vector<char>> &board, string &word, vector<vector<bool>> &visited, int row, int col, int pos) {
        int m = board.size();
        int n = board[0].size();
        if(pos >= word.size()) return true;
        if(row < 0 || col < 0 || row >= m || col >= n || visited[row][col]) return false;
        if(board[row][col] != word[pos]) return false;
        visited[row][col] = true;
        for(int i = 0;i < 4;i++) {
            int nr = row + adj[i].first;
            int nc = col + adj[i].second;
            if(solve(board,word,visited,nr,nc,pos+1)) return true;
        }
        visited[row][col] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(board[i][j] == word[0]) {
                    if(solve(board,word,visited,i,j,0)) return true;
                }
            }
        }
        return false;
    }
};
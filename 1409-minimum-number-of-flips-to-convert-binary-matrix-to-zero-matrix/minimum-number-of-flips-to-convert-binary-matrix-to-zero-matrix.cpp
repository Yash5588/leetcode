class Solution {
public:
    vector<pair<int,int>> adj = {{-1,0},{1,0},{0,1},{0,-1}};
    int minFlips(vector<vector<int>>& mat) {
        unordered_set<int> visited;
        queue<pair<int,int>> que;
        int mask = 0;
        int m = mat.size();
        int n = mat[0].size();

        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                int shift = i*n + j;
                if(mat[i][j] == 1) {
                    mask |= (1 << shift);
                }
            }
        }

        que.push({mask,0});
        while(!que.empty()) {
            int curr_mask = que.front().first;
            int operations = que.front().second;
            que.pop();
            if(curr_mask == 0) return operations;
            if(visited.find(curr_mask) != visited.end()) continue;
            visited.insert(curr_mask);
            //flip and check for each bit
            int new_mask = 0;
            for(int i = 0;i < m;i++) {
                for(int j = 0;j < n;j++) {
                    int pos = i*n + j;
                    new_mask = curr_mask;
                    //flip current bit
                    new_mask ^= (1 << pos);
                    for(int k = 0;k < 4;k++) {
                        int new_row = i + adj[k].first;
                        int new_col = j + adj[k].second;
                        //flip all neighbors
                        if(new_row >= 0 && new_row < m && new_col >= 0 && new_col < n) {
                            int new_pos = new_row*n + new_col;
                            new_mask ^= (1 << new_pos);
                        }
                    }
                    que.push({new_mask, operations+1});
                }
            }
        }
        return -1;
    }
};
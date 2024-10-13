class Solution {
public:
    unordered_map<int,bool> visited;
    void dfs(int ind, vector<vector<int>> &stones) {
        visited[ind] = true;
        for(int i = 0;i < stones.size();i++) {
            if(!visited[i]) {
                if(stones[i][0] == stones[ind][0] || stones[i][1] == stones[ind][1]) {
                    dfs(i, stones);
                }
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int cnt = 0;
        for(int i = 0;i < stones.size();i++) {
            if(!visited[i]) {
                cout << i << endl;
                cnt++;
                dfs(i,stones);
            }
        }
        return stones.size() - cnt;
    }
};
class Solution {
public:
    unordered_map<int, vector<int>> adj;
    unordered_map<int,int> children;
    int getChildren(int root, int parent) {
        int cnt = 0;
        for(auto &child : adj[root]) {
            if(child != parent) cnt += getChildren(child,root);
        }
        children[root] = cnt + 1;
        return cnt + 1;
    }

    int getScore(int root) {
        int score = 0;
        queue<pair<int,int>> que;
        que.push({0,-1});
        int k = 0;
        while(!que.empty()) {
            int size = que.size();
            score += k*size;
            while(size--) {
                int node = que.front().first;
                int parent = que.front().second;
                que.pop();
                for(auto &child : adj[node]) {
                    if(child != parent) {
                        que.push({child,node});
                    }
                }
            }
            k++;
        }
        return score;
    }

    void assignScore(int root, int parent, vector<int> &res) {
        int n = res.size();
        res[root] = res[parent] - children[root] + (n - children[root]);
        for(auto &child : adj[root]) {
            if(child != parent) assignScore(child, root, res);
        } 
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        for(auto &x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        children[0] = getChildren(0,-1);
        int root_score = getScore(0);
        vector<int> res(n,0);
        res[0] = root_score;
        for(auto &child : adj[0]) {
            assignScore(child,0,res);
        }
        return res;
    }
};
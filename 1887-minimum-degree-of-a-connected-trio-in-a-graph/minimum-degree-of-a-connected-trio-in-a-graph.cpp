class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        //use adjacency list for dence graph
        vector<vector<int>> adj(n+1, vector<int> (n+1,0));
        vector<int> degree(n+1,0);
        for(auto &edge : edges) {
            degree[edge[0]]++;
            degree[edge[1]]++;
            adj[edge[0]][edge[1]] = 1;
            adj[edge[1]][edge[0]] = 1;
        }

        int mi = INT_MAX;
        //check if there is an edge bet each node of list extra
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j < n;j++) {
                for(int k = j+1;k <= n;k++) {
                    if(adj[i][j] == 1 && adj[i][k] == 1 && adj[j][k] == 1) {
                        //remove inner trio edges which is 2 degree for each edge
                        mi = min(mi, degree[i] + degree[j] + degree[k] - 6);
                    }
                }
            }
        }
        return mi == INT_MAX ? -1 : mi;
    }
};
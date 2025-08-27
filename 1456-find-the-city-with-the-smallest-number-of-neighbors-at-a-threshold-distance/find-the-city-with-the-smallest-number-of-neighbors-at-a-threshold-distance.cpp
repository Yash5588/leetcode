class Solution {
public:
    void floyd_warshall(vector<vector<int>> &adj_matrix) {
        int n = adj_matrix.size();
        for(int i = 0;i < n;i++) {
            adj_matrix[i][i] = 0;
        }

        for(int k = 0;k < n;k++) {
            for(int i = 0;i < n;i++) {
                for(int j = 0;j < n;j++) {
                    adj_matrix[i][j] = min(adj_matrix[i][j], adj_matrix[i][k] + adj_matrix[k][j]);
                }
            }
        }


    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj_matrix(n, vector<int>(n,1e9));
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj_matrix[u][v] = edge[2];
            adj_matrix[v][u] = edge[2];
        }
        floyd_warshall(adj_matrix);
        int mnm = INT_MAX;
        int city = 0;
        for(int i = 0;i < n;i++) {
            int cnt = 0;
            for(int j = 0;j < n;j++) {
                if(distanceThreshold >= adj_matrix[i][j] && i != j) {
                    cnt++;
                }
            }
            if(mnm >= cnt) {
                mnm = cnt;
                city = i;
            }
        }
        return city;
    }
};
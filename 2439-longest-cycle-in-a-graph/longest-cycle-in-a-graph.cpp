class Solution {
public:
    bool isCycle(int node, vector<int> &edges, vector<int> &visited, vector<int> &path_visited, int cnt) {
        visited[node] = 1;
        path_visited[node] = cnt;
        int child = edges[node];
        if(child != -1) {
            if(!visited[child] && isCycle(child, edges, visited, path_visited, cnt+1)) return true;
            else if(path_visited[child] != 0) return true;
        }
        visited[node] = 0;
        return false;
    }

    void topoSort(int n, vector<int> &edges, vector<int> &path_visited) {
        vector<int> indegree(n,0);
        for(int i = 0;i < n;i++) {
            if(edges[i] != -1)  indegree[edges[i]]++;
        }
        queue<int> que;
        for(int i = 0;i < n;i++) {
            if(indegree[i] == 0) {
                que.push(i);
                path_visited[i] = -1;
            }
        }

        while(!que.empty()) {
            int node = que.front();
            que.pop();
            int child = edges[node];
            if(child != -1) {
                indegree[child]--;
                if(indegree[child] == 0) {
                    path_visited[child] = -1;
                    que.push(child);
                }
            }
        }
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> visited(n, 0);
        vector<int> path_visited(n, 0);

        //remove all the nodes which are not participating in the cycle using kahn's algorithm and mark path_visited as -1
        topoSort(n, edges, path_visited);

        //now for all the edges which participated in cycle
        for(int i = 0;i < n;i++) {
            if(path_visited[i] == 0) {
                isCycle(i, edges, visited, path_visited, 1);
            }
        }

        //now get the cycle with max length whose length is stored in path visited
        int ma = INT_MIN;
        for(int i = 0;i < n;i++) {
            ma = max(ma, path_visited[i]);
        }
        return ma;
    }
};
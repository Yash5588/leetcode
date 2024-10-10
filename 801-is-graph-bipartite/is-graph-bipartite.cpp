class Solution {
public:
    unordered_set<int> even,odd;
    unordered_map<int,bool> visited;
    bool dfs(int node, vector<vector<int>> &graph, int cnt) {
        if(visited[node]) return true;
        visited[node] = true;
        if(cnt & 1) odd.insert(node);
        else even.insert(node);
        // cout << node << endl;
        bool flag = true;
        for(auto &child : graph[node]) {
            //parent in odd
            if(cnt & 1) {
                //child same set as parent
                if(odd.find(child) != odd.end()) {
                    return false;
                }
                //child not in opposite set basically not visited
                else if(even.find(child) == even.end()) {
                    flag &= dfs(child, graph, cnt+1);
                }
            }
            //parent in even
            else {
                //same as parent set(even)
                if(even.find(child) != even.end()) {
                    return false;
                }
                //not in both sets basically not visited
                else if(odd.find(child) == odd.end()) {
                    flag &= dfs(child, graph, cnt+1);
                }
            }
        }
        return flag;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        for(int i = 0;i < V;i++) {
            if(!visited[i]) {
                if(!dfs(i, graph, 0)) return false;
            }
        }
        return true;
    }
};
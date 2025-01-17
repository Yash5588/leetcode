class Solution {
public:
    void solve(int node, vector<vector<int>> &graph, vector<int> path, set<vector<int>> &paths) {
        //push current node in path
        path.push_back(node);
        if(node == graph.size()-1) {
            //check and update the path if we reached the destination
            paths.insert(path);
        }
        for(auto &child : graph[node]) {
            //recursively check for each child
            solve(child,graph,path,paths);
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int V = graph.size();
        //set to avoid duplicate paths
        set<vector<int>> paths;
        solve(0,graph,{},paths);
        //type cast to vector
        return vector<vector<int>> (paths.begin(),paths.end());
    }
};
class Solution {
public:
    unordered_map<char,vector<char>> adj;
    bool dfs(char node, char target, unordered_map<char,bool> &visited) {
        visited[node] = true;
        for(auto &child : adj[node]) {
            if(!visited[child]) {
                if(child == target) return true;
                else if(dfs(child,target,visited)) return true;
            }
        }
        return false;
    }
    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();
        for(auto &eq : equations) {
            if(eq[1] == '=') {
                adj[eq[0]].push_back(eq[3]);
                adj[eq[3]].push_back(eq[0]);
            }
        }
        for(auto &eq : equations) {
            vector<char> vec = adj[eq[0]];
            if(eq[1] == '!') {
                unordered_map<char,bool> visited;
                if(eq[0] == eq[3]) return false;
                if(dfs(eq[0],eq[3],visited)) return false;
            }
        }
        return true;
    }
};
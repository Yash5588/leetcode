class Solution {
public:
    unordered_map<int,unordered_set<int>> adj;
    int getQuiet(int node, vector<int> &quiet, vector<int> &answer) {
        int min_node = node;
        for(auto &child : adj[node]) {
            if(answer[child] == -1) {
                int no =  getQuiet(child, quiet, answer);
                if(quiet[no] < quiet[min_node]) {
                    min_node = no;
                }
            }
            else {
                int no = answer[child];
                if(quiet[no] < quiet[min_node]) {
                    min_node = no;
                }
            }
        }
        answer[node] = min_node;
        return min_node;
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        for(auto &x : richer) {
            adj[x[1]].insert(x[0]);
        }
        vector<int> answer(n,-1);
        for(int i = 0;i < n;i++) {
            if(answer[i] == -1) {
                getQuiet(i, quiet, answer);
            }
        }
        return answer;
    }
};
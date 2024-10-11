class Solution {
public:
    unordered_map<int,vector<int>> adj;
    int getQuiet(int node, vector<int> &quiet, vector<int> &answer) {
        int min_node = node;
        for(auto &child : adj[node]) {
            int no = -1;
            if(answer[child] == -1) {
                no =  getQuiet(child, quiet, answer);
            }
            else {
                no = answer[child];
            }
            if(quiet[no] < quiet[min_node]) {
                min_node = no;
            }
        }
        answer[node] = min_node;
        return min_node;
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        for(auto &x : richer) {
            adj[x[1]].push_back(x[0]);
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
class Solution {
public:
    unordered_map<string,vector<pair<string,double>>> adj;
    unordered_map<string,double> convert1;
    void dfs1(string node, double cost, string parent) {
        for(auto &child : adj[node]) {
            string str = child.first;
            double wt = child.second;
            if(str != parent) {
                convert1[str] = max(convert1[str], cost * wt);
                dfs1(str, cost * wt, node);
            }
        }
    }
    void dfs2(string node, double cost, string dst, double &res, string parent) {
        if(node == dst) res = max(res, cost);
        for(auto &child : adj[node]) {
            string str = child.first;
            double wt = child.second;
            if(str != parent) {
                dfs2(str, cost * wt, dst, res, node);
            }
        }
    }
    
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        int n1 = rates1.size();
        int n2 = rates2.size();
        for(int i = 0;i < n1;i++) {
            adj[pairs1[i][0]].push_back({pairs1[i][1], rates1[i]});
            adj[pairs1[i][1]].push_back({pairs1[i][0], 1/rates1[i]});
        }
        dfs1(initialCurrency, 1, initialCurrency);
        adj.clear();
        for(int i = 0;i < n2;i++) {
            adj[pairs2[i][0]].push_back({pairs2[i][1], rates2[i]});
            adj[pairs2[i][1]].push_back({pairs2[i][0], 1/rates2[i]});
        }
        double ma = 0.0;
        for(auto &[start,cst] : convert1) {
            double res = 1;
            dfs2(start, cst, initialCurrency, res, start);
            ma = max(ma, res);
        }
        return ma;
    }
};
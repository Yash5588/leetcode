class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<set<pair<int,int>>> rows(m);
        vector<set<pair<int,int>>> cols(n);
        vector<vector<int>> values;
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                values.push_back({mat[i][j],i,j});
            }
        }
        sort(values.begin(),values.end());
        int ans = 0;
        for(auto &val : values) {
            int res = 1;
            int ele = val[0];
            int r = val[1];
            int c = val[2];
            auto iter = rows[r].lower_bound({ele,0});
            if(!rows[r].empty() && iter != rows[r].begin()) {
                iter--;
                res = max(res, 1 + iter->second); //store nearest result which should max possible
            }

            iter = cols[c].lower_bound({ele,0});
            if(!cols[c].empty() && iter != cols[c].begin()) {
                iter--;
                res = max(res, 1 + iter->second);
            }
            // cout << ele << ' ' << res << endl;
            rows[r].insert({ele,res});
            cols[c].insert({ele,res});

            ans = max(ans, res);
        }
        return ans;
    }
};
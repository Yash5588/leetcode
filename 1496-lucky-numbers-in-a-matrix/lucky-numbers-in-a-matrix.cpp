class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<int> r_min(n),c_max(m);
        for(int i=0;i<n;i++) {
            r_min[i] = *min_element(a[i].begin(),a[i].end());
        }
        for(int j=0;j<m;j++) {
            int ma = INT_MIN;
            for(int i=0;i<n;i++) {
                ma = max(ma, a[i][j]);
            }
            c_max[j] = ma;
        }
        vector<int> ans;
        for(auto &r : r_min) {
            for(auto &c : c_max) {
                if(r == c) {
                    ans.push_back(r);
                    break;
                }
            }
        }
        return ans;
        
    }
};
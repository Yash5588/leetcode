class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> start(n);
        unordered_map<int,int> ind;
        for(int i = 0;i < n;i++) {
            start[i] = intervals[i][0];
            ind[start[i]] = i;
        }
        sort(start.begin(),start.end());
        vector<int> res;
        for(int i = 0;i < n;i++) {
            int g_ind = lower_bound(start.begin(),start.end(),intervals[i][1]) - start.begin();
            if(g_ind == n) res.push_back(-1);
            else res.push_back(ind[start[g_ind]]);
        } 
        return res;
    }
};
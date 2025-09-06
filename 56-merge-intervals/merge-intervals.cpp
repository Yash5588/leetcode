class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> res;
        int idx = 0;
        while(idx < n) {
            res.push_back(intervals[idx]);
            while(idx < n && intervals[idx][0] <= res.back()[1]) {
                res.back()[1] = max(res.back()[1], intervals[idx][1]);
                idx++;
            }
        }
        return res;
    }
};
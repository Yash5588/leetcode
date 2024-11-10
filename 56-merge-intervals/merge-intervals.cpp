class Solution {
public:
    bool isMerged(vector<int> &int1, vector<int> &int2) {
        if(int1[0] <= int2[0] && int2[0] <= int1[1]) return true;
        if(int1[0] <= int2[1] && int2[1] <= int1[1]) return true;
        if(int2[0] <= int1[0] && int1[0] <= int2[1]) return true;
        if(int2[0] <= int1[1] && int1[1] <= int2[1]) return true;
        return false;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        int i = 0,j;
        while(i < n) {
            j = i+1;
            while(j < n && isMerged(intervals[i],intervals[j])) {
                intervals[i][0] = min(intervals[i][0], intervals[j][0]);
                intervals[i][1] = max(intervals[i][1], intervals[j][1]);
                j++;
            }
            res.push_back(intervals[i]);
            i = j;
        }
        return res;
    }
};
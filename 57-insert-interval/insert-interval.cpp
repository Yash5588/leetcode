class Solution {
public:
    bool isMerged(vector<int> int1, vector<int> int2) {
        if(min(int1[0],int1[1]) >= int2[0] && min(int1[0],int1[1]) <= int2[1]) return true;
        if(max(int1[0],int1[1]) >= int2[0] && max(int1[0],int1[1]) <= int2[1]) return true;
        if(min(int2[0],int2[1]) >= int1[0] && min(int2[0],int2[1]) <= int1[1]) return true;
        if(max(int2[0],int2[1]) >= int1[0] && max(int2[0],int2[1]) <= int1[1]) return true;
        return false;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;
        vector<bool> flag(n,false);
        for(int i = 0;i < n;i++) {
            if(isMerged(intervals[i],newInterval)) {
                newInterval[0] = min(newInterval[0],intervals[i][0]);
                newInterval[1] = max(newInterval[1],intervals[i][1]);
                flag[i] = true;
            }
        }
        // for(auto x : flag) cout << x << endl;
        int i = 0;
        while(i < n && !flag[i]) {
            ans.push_back(intervals[i]);
            i++;
        }
        while(i < n && flag[i]) i++;
        ans.push_back(newInterval);
        while(i < n) {
            ans.push_back(intervals[i]);
            i++;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
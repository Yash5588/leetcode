class Solution {
public:
    bool isMerged(vector<int> &int1, vector<int> &int2) {
        if(int1[0] <= int2[0] && int2[0] <= int1[1]) return true;
        if(int1[0] <= int2[1] && int2[1] <= int1[1]) return true;
        if(int2[0] <= int1[0] && int1[0] <= int2[1]) return true;
        if(int2[0] <= int1[1] && int1[1] <= int2[1]) return true;
        return false;
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int n = points.size();
        int cnt = 0;
        int i = 0,j = 0;
        while(i < n) {
            j = i+1;
            while(j < n && isMerged(points[i],points[j])) {
                points[i][0] = max(points[i][0],points[j][0]);
                points[i][1] = min(points[i][1],points[j][1]);
                j++;
            }
            cnt++;
            i = j;
        }
        return cnt;
    }
};
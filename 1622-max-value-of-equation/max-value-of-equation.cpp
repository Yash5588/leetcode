class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        int ma = INT_MIN;
        priority_queue<pair<int,int>> que;
        for(auto point : points) {
            while(!que.empty() && point[0] - que.top().second > k) que.pop();
            if(!que.empty()) {
                ma = max(ma, que.top().first + point[0] + point[1]);
            }
            que.push({point[1]-point[0] , point[0]});
        }
        return ma;
    }
};
class Solution {
public:
    double distance(vector<int> point) {
        return sqrt(pow(point[0],2) + pow(point[1],2));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<double,vector<int>>> que;
        for(int i = 0;i < n;i++) {
            double dist = distance(points[i]);
            que.push({dist,{points[i][0],points[i][1]}});
            if(i >= k) que.pop();
        }
        vector<vector<int>> res;
        while(!que.empty()) {
            vector<int> point = que.top().second;
            res.push_back(point);
            que.pop();
        }
        return res;
    }
};
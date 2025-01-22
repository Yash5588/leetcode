class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        int ma = INT_MIN;

        //given equation = yi + yj + |xi - xj|
        //now xj > xi so eq is (yi + yj + xj - xi)
        //now segregate them ((yi - xi) + (xj + yj)) for i < j

        priority_queue<pair<int,int>> que; //{yj-xj, xj} for all j
        for(auto point : points) {
            //eliminate all top values which are of no use or not in range
            while(!que.empty() && point[0] - que.top().second > k) que.pop();
            //get top most value which is in range
            if(!que.empty()) {
                ma = max(ma, que.top().first + point[0] + point[1]);
            }
            //store in que 
            que.push({point[1]-point[0] , point[0]});
        }
        return ma;
    }
};
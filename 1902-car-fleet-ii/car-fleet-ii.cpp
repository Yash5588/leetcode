class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> res(n);
        stack<int> sta;
        for(int i = n-1;i >= 0;i--) {
            while(!sta.empty() && cars[sta.top()][1] >= cars[i][1]) {
                sta.pop();
            }
            if(sta.empty()) res[i] = -1;
            else {
                while(!sta.empty()) {
                    double dist = cars[sta.top()][0] - cars[i][0];
                    double speed = cars[i][1] - cars[sta.top()][1];
                    double time = dist/speed;
                    if(time <= res[sta.top()] || res[sta.top()] == -1) {
                        res[i] = time;
                        break;
                    }
                    sta.pop();
                }
            }
            sta.push(i);
        }
        return res;
    }
};
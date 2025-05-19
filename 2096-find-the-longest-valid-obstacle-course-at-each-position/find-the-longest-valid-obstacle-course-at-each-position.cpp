class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> store, res;
        for(int i = 0;i < n;i++) {
            int idx = upper_bound(store.begin(), store.end(), obstacles[i]) - store.begin();
            if(idx == store.size()) {
                res.push_back(store.size()+1);
                store.push_back(obstacles[i]);
            }
            else {
                res.push_back(idx+1);
                store[idx] = obstacles[i];
            }
        }
        return res;
    }
};
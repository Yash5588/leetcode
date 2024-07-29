class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        int n = pos.size();
        vector<pair<int,int>> pos_speed(n);
        for(int i=0;i<n;i++) {
            pos_speed[i] = {pos[i],speed[i]};
        }
        unordered_set<double> ans;
        sort(pos_speed.begin(),pos_speed.end());
        stack<double> sta;
        for(int i=n-1;i>=0;i--) {
            double time = (target - pos_speed[i].first) / (double)pos_speed[i].second;
            while(!sta.empty() && sta.top() < time) {
                sta.pop();
            }
            if(!sta.empty()) {
                ans.insert(sta.top());
                sta.push(sta.top());
            }
            else {
                ans.insert(time);
                sta.push(time);
            }
        }
        ans.insert(sta.top());
        return ans.size();
    }
};
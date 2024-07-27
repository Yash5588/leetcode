class Solution {
public:
    // 1) this problem is application of next greater element in array
    // 2) use monotically decreasing stack and iterate from backwards
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        stack<pair<int,int>> sta;
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--) {
            int pops = 0;
            while(!sta.empty() && sta.top().first <= temp[i]) {
                pops += sta.top().second;
                sta.pop();
            }
            if(sta.empty()) ans[i] = 0;
            else ans[i] = pops+1;
            sta.push({temp[i],pops+1}); 
        }
        return ans;
    }
};
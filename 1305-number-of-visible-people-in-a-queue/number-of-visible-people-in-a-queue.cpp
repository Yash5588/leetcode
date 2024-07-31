class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        stack<int> sta;
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--) {
            int c = 0;
            while(!sta.empty() && sta.top() <= heights[i]) {
                c++;
                sta.pop();
            }
            if(sta.empty()) ans[i] = c;
            else ans[i]= c+1;
            sta.push(heights[i]);
        }
        return ans;
    }
};
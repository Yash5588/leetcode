class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        int ma = INT_MIN;
        int ind = 0;
        int n = a.size();
        for(int i=0;i<n;i++) {
            if(ma < a[i]) {
                ma = a[i];
                ind = i;
            }
        }
        stack<int> sta;
        vector<int> ans(n,-1);
        for(int i=ind;i>=0;i--) {
            while(!sta.empty() && sta.top()<=a[i]) {
                sta.pop();
            }
            if(!sta.empty()) ans[i] = sta.top();
            sta.push(a[i]);
        }
        for(int i=n-1;i>ind;i--) {
            while(!sta.empty() && sta.top()<=a[i]) {
                sta.pop();
            }
            if(!sta.empty()) ans[i] = sta.top();
            sta.push(a[i]);
        }
        return ans;
    }
};
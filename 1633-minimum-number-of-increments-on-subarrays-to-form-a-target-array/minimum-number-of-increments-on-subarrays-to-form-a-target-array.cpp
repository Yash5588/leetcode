class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        stack<int> sta;
        sta.push(0);
        int ans = 0;
        for(int i=0;i<n;i++) {
            bool flag = false;
            while(!sta.empty() && sta.top() <= target[i]) {
                if(!flag) {
                    ans += target[i]-sta.top();
                    flag = true;
                }
                sta.pop();
            }
            sta.push(target[i]);
        }
        return ans;
    }
};
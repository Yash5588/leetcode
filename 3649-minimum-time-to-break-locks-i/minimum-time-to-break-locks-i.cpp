class Solution {
public:
    int ans = INT_MAX;
    void solve(vector<int> &strength, int k, int x, int time, int mask) {
        int n = strength.size();
        if(mask == pow(2,n)-1) {
            ans = min(ans, time);
            return;
        }
        for(int i = 0;i < n;i++) {
            if(mask & (1 << i)) continue;
            int extra = 0;
            if(strength[i]%x == 0) extra = strength[i]/x;
            else extra = strength[i]/x + 1;
            solve(strength, k, x+k, time+extra, mask | (1 << i));
        }
    }
    int findMinimumTime(vector<int>& strength, int k) {
        int n = strength.size();
        sort(strength.begin(),strength.end());
        solve(strength,k,1,0,0);
        return ans;
    }
};
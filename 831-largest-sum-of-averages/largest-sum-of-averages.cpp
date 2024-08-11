class Solution {
public:
    double dp[105][105][105];
    double partition(vector<int> &prefix, int n, int k, int prev, int pos) {
        if(pos == n) return 0;
        if(k == 1) {
            return (prefix[n-1] - prefix[prev-1])/(double)(n-prev);
        }
        if(dp[pos][prev][k] != -1.0) return dp[pos][prev][k];
        double ma = 0;
        for(int i=pos;i<n;i++) {
            if(n - i <= k) {
                ma = max(ma, (prefix[i]-prefix[prev-1])/(double)(i-prev+1) + partition(prefix, n, k-1, i+1, i+1));
            }
            else {
                double pick = (prefix[i]-prefix[prev-1])/(double(i-prev+1)) + partition(prefix, n, k-1, i+1, i+1);
                double not_pick = partition(prefix, n, k, prev, i+1);
                ma = max(ma, max(pick,not_pick));
            }
        }
        return dp[pos][prev][k] = ma;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n+1,0);
        for(int i=1;i<=n;i++) {
            prefix[i] = prefix[i-1] + nums[i-1];
        }
        n++;
        for(int i=0;i<105;i++) {
            for(int j=0;j<105;j++) {
                for(int k=0;k<105;k++) {
                    dp[i][j][k] = -1.0;
                }
            }
        }
        return partition(prefix, n, k, 1, 1);
    }
};
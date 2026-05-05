class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mxm = prices[n-1];
        int res = 0;
        for(int i = n-1;i >= 0;i--) {
            res = max(res, mxm - prices[i]);
            mxm = max(mxm, prices[i]);
        }
        return res;
    }
};
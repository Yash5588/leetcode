class Solution {
public:
    int getDays(vector<int> &wts, int days, int limit) {
        int n = wts.size();
        int cnt = 1;
        int val = 0;
        for(int i = 0;i < n;i++) {
            if(val + wts[i] <= limit) {
                val += wts[i];
            }
            else {
                cnt++;
                val = wts[i];
            }
        }
        return cnt;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(),weights.end());
        int high = 1e9;
        int res = -1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(getDays(weights, days, mid) <= days) {
                res = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return res;
    }
};
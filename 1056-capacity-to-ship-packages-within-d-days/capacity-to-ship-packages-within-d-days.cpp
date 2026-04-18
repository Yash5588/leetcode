class Solution {
public:
    bool valid(int capacity, vector<int> &weights, int days) {
        long long total = 0;
        long long sum = 0;
        for(auto &x : weights) {
            if(sum + x <= capacity) {
                sum += x;
            }
            else {
                sum = x;
                total++;
            }
        }
        total++;
        return total <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(valid(mid,weights,days)) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};
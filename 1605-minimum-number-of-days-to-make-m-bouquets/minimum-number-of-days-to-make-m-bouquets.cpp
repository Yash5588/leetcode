class Solution {
public:
    bool valid(int days, vector<int> &nums, int m, int k) {
        long long total = 0;
        int cnt = 0;
        for(auto &x : nums) {
            if(x <= days) {
                cnt++;
            }
            else {
                total += cnt/k;
                cnt = 0;
            }
        }
        total += cnt/k;
        return total >= m;
    }
    int minDays(vector<int>& nums, int m, int k) {
        int n = nums.size();
        if((long long)m*k > n) return -1;
        int low = 1, high = 1e9;
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(valid(mid, nums, m, k)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
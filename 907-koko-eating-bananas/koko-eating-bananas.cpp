class Solution {
public:
    bool valid(int k, vector<int> &piles, int h) {
        long long total = 0;
        for(auto &x : piles) {
            int val = (x+k-1)/k;
            total += val;
        }
        return total <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = 1e9;
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(valid(mid, piles,h)) {
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
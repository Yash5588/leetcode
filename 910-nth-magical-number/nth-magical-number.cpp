class Solution {
public:
    long long getNumPos(long long mid, int a, int b) {
        return mid/a + mid/b - mid/lcm(a,b);
    }
    int mod = 1e9 + 7;
    int nthMagicalNumber(int n, int a, int b) {
        long long low = 2,high = LONG_MAX;
        long long res = -1;
        while(low <= high) {
            long long mid = low + (high - low)/2;
            if(getNumPos(mid,a,b) >= n) {
                res = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return res%mod;
    }
};
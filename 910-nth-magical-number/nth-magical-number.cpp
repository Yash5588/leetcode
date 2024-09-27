class Solution {
public:
    //find the position of that number
    long long getNumPos(long long mid, int a, int b) {
        return mid/a + mid/b - mid/lcm(a,b);
    }
    int mod = 1e9 + 7;
    int nthMagicalNumber(int n, int a, int b) {
        long long low = 2,high = LONG_MAX;
        long long res = -1;
        while(low <= high) {
            long long mid = low + (high - low)/2;
            //get the values which satisfies the position of n
            //but they should be multiple of either a or b
            //so we are going to store all values which can be of position n
            //but we need smallest among them so we store ans at each iteration
            if(getNumPos(mid,a,b) >= n) {
                res = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return res%mod;
    }
};
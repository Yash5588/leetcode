class Solution {
public:
    int divide(int dividend, int divisor) {
        bool positive = true;
        if(dividend == divisor) return 1;
        if(dividend >= 0 && divisor < 0) positive = false;
        if(dividend < 0 && divisor > 0) positive = false;
        long long numer = abs(dividend);
        long long deno = abs(divisor);
        long long ans = 0;
        while(deno <= numer) {
            long long cnt = 0;
            while(numer >= (deno << (cnt+1))) {
                cnt++;
            }
            ans += (1LL << cnt);
            numer -= (deno << cnt);
        }
        if(ans > INT_MAX) {
            if(positive) return INT_MAX;
            return INT_MIN;
        }
        return (positive) ? ans : (-1 * ans);

    }
};
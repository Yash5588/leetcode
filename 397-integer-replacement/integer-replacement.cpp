class Solution {
public:
    long long integerReplacement(long long n) {
        if(n == 1) return 0;
        if(n & 1) {
            return 1LL + min(integerReplacement(n+1), integerReplacement(n-1));
        }
        return 1LL + integerReplacement(n/2);
    }
};
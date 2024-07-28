class Solution {
public:
    bool isPrime(long long n) {
        if(n == 1) return false;
        if(n == 2) return true;
        if(n % 2 == 0) return false;
        for(int i=2;i<=sqrtl(n);i++) {
            if(n % i == 0) return false;
        }
        return true;
    }
    int nonSpecialCount(int l, int r) {
        long long c = 0;
        for(int i=1;i<=100000;i++) {
            if(i*i >= l && i*i<=r && isPrime(i)) c++;
            if(i*i>r) break;
        }
        return r-l+1-c;
    }
};
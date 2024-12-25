class Solution {
public:
    int solve(int n, int mask, int currPos) {
        if(currPos > n) return 1;
        int cnt = 0;
        for(int i = 1;i <= n;i++) {
            if(mask & (1 << (i-1))) continue;
            if(i % currPos == 0 || currPos % i == 0) {
                cnt += solve(n, mask | (1 << (i-1)), currPos+1);
            }
        }
        return cnt;
    }
    int countArrangement(int n) {
        return solve(n, 0, 1);
        
    }
};
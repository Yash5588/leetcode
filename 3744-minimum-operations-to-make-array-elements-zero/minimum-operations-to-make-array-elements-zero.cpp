class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long res = 0;
        for(auto &q : queries) {
            long long l = q[0];
            long long r = q[1];
            long long sum = 0;
            int k = 0;
            long long low = 1;
            while(low <= 1e9) {
                long long high = low * 4;
                if(low > r) break;
                long long start = max(low, l);
                long long end = min(high-1, r);
                if(start <= end) {
                    long long cnt = end - start + 1;
                    long long opers = (k+1)*cnt;
                    sum += opers;
                }
                k++;
                low = high;
            }
            res += (sum + 1)/2;
        }
        return res;
    }
};
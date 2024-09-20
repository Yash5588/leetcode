class Solution {
public:
    long long countZeros(long long num) {
        long long count = 0;
        long long start = 5;
        while(start <= num) {
            count += num/start;
            start *= 5;
        }
        return count;
    }
    int preimageSizeFZF(int k) {
        long long ans = 0;
        long long low = 0;
        long long high = 6*(long long)k;
        while(low <= high) {
            long long mid = low + (high - low)/2;
            long long zeros = countZeros(mid);
            if(zeros < k) low = mid + 1;
            else if(zeros > k) high = mid - 1;
            else {
                ans = 5;
                break;
            }
        }
        return ans;
    }
};
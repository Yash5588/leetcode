class Solution {
public:
    long long getCount(int num) {
        long long count = num;
        string str = to_string(num);
        long long n = str.length();
        for(int i = 1;i < n;i++) {
            count += (num - ((long long)pow(10,i) - 1));
        }
        return count;
    }
    int findNthDigit(int n) {
        long long low = 0,high = n;
        long long ans = -1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(getCount(mid) >= n) {
                ans = mid;
                high = mid - 1;
            } 
            else low = mid + 1;
        }
        string str = to_string(ans);
        long long size = str.length();
        long long ind = size - (getCount(ans)-n) - 1;
        return str[ind] - '0';
    }
};
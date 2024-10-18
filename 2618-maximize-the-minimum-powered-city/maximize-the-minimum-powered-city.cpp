class Solution {
public:
    bool isPossible(vector<int> stations, long long power, int r, int k) {
        int n = stations.size();
        long long sum = 0;
        for(int i = 0;i < r;i++) {
            sum += stations[i];
        }
        for(int i = 0;i < n;i++) {
            if(i+r < n) sum += stations[i+r];
            if(i-r-1 >= 0) sum -= stations[i-r-1];
            long long req = 0;
            if(sum < power) {
                req = power - sum;
            }
            if(req > k) return false;
            k -= req;
            if(i+r < n) stations[i+r] += req;
            sum += req;
        }
        return true;
    }
    long long maxPower(vector<int>& stations, int r, int k) {
        long long low = 0;
        long long high = k;
        for(auto &x : stations) high += x;
        long long ans = -1;
        while(low <= high) {
            long long mid = low + (high - low)/2;
            if(isPossible(stations,mid,r,k)) {
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};
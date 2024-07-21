class Solution {
public:
    long long minimumOperations(vector<int>& a, vector<int>& tar) {
        long long n = a.size();
        vector<long long> diff(n);
        for(int i=0;i<n;i++) {
            diff[i] = tar[i] - a[i];
        }
        long long ans = abs(diff[0]);
        for(int i=1;i<n;i++) {
            if((diff[i-1]>0) ^ (diff[i]<0)) {
                if(abs(diff[i-1]) < abs(diff[i])) {
                    ans += abs(diff[i]) - abs(diff[i-1]);
                }
            }
            else {
                ans += abs(diff[i]);
            }
        }
        return ans;
    }
};
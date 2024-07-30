class Solution {
public:
    int MOD = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<pair<long long,long long>> sta1,sta2;
        vector<long long> left(n);
        vector<long long> right(n);
        for(int i=0;i<n;i++) {
            long long c = 0;
            while(!sta1.empty() && sta1.top().first >= arr[i]) {
                c += sta1.top().second;
                sta1.pop();
            }
            left[i] = c+1;
            sta1.push({arr[i],c+1});
        }
        for(int i=n-1;i>=0;i--) {
            long long c = 0;
            while(!sta2.empty() && sta2.top().first > arr[i]) {
                c += sta2.top().second;
                sta2.pop();
            }
            right[i] = c+1;
            sta2.push({arr[i],c+1});
        }
        long long ans = 0;
        for(int i=0;i<n;i++) {
            cout << left[i] << ' ' << right[i] << endl;
            ans = (((ans + ((left[i]*right[i]) % MOD) * arr[i]) % MOD) + MOD) % MOD;
        }
        return ans;
    }
};
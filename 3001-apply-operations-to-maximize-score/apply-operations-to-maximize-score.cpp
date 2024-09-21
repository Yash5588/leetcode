class Solution {
public:
    int mod = 1e9 + 7;
    long long power(long long base, long long exp) {
        long long res = 1;
        while(exp > 0) {
            if(exp & 1) res = (res * base) % mod;
            exp = exp >> 1;
            base = (base * base) % mod;
        }
        return res;
    }
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int N = 1e5 + 1;
        vector<long long> pscore(N,0);
        for(int i = 2;i < N;i++) {
            if(pscore[i] > 0) continue;
            for(int j = i;j < N;j += i) {
                pscore[j]++;
            }
        }
        stack<pair<long long,long long>> sta1,sta2;
        vector<long long> left(n,0),right(n,0);
        for(int i = 0;i < n;i++) {
            long long c = 0;
            while(!sta1.empty() && sta1.top().first < pscore[nums[i]]) {
                c += sta1.top().second;
                sta1.pop();
            }
            left[i] = c;
            sta1.push({pscore[nums[i]],c + 1});
        }
        for(int i = n-1;i >= 0;i--) {
            long long c = 0;
            while(!sta2.empty() && sta2.top().first <= pscore[nums[i]]) {
                c += sta2.top().second;
                sta2.pop();
            }
            right[i] = c;
            sta2.push({pscore[nums[i]],c + 1});
        }
        vector<vector<long long>> combine(n);
        for(int i = 0;i < n;i++) {
            combine[i] = {nums[i],left[i],right[i]};
        }
        // for(auto &x : nums) cout << pscore[x] << endl;
        // cout << endl;
        // for(auto &x : left) cout << x << endl;
        // cout << endl;
        // for(auto &x : right) cout << x << endl;
        sort(combine.begin(),combine.end(),greater<vector<long long>>());
        long long res = 1;
        for(int i = 0;i < n;i++) {
            if(k <= 0) break;
            long long pow = min((long long)k, 1 + combine[i][1] + combine[i][2] + combine[i][1]*combine[i][2]);
            res = (res * power(combine[i][0],pow)) % mod;
            k -= pow;
        }
        return res;
    }
};
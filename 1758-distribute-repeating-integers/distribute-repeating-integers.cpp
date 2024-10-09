class Solution {
public:
    int dp[100][1<<11];
    bool isValid(int prevMask, int mask, vector<int> &quantity, int freq) {
        if((prevMask & mask) != 0) return false;
        int m = quantity.size();
        int sum = 0;
        for(int i = 0;i < m;i++) {
            if(mask & (1 << i)) {
                sum += quantity[i];
            }
        }
        return freq >= sum;
    }
    bool solve(vector<int> &freq, vector<int> &quantity, int pos, int mask) {
        int n = freq.size();
        int m = quantity.size();
        if(mask == pow(2,m) - 1) return true;
        if(pos >= n) return false;
        if(dp[pos][mask] != -1) return dp[pos][mask];
        bool ans = false;
        for(int i = 0;i < pow(2,m);i++) {
            if(isValid(mask, i, quantity, freq[pos])) {
                ans = ans | solve(freq, quantity, pos+1, mask | i);
                if(ans) return dp[pos][mask] = true;
            }
        }
        return dp[pos][mask] = ans;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        int n = nums.size();
        map<int,int> count;
        for(int i = 0;i < n;i++) {
            count[nums[i]]++;
        }
        vector<int> freq;
        for(auto &[key,value] : count) {
            freq.push_back(value);
        }
        memset(dp,-1,sizeof(dp));
        return solve(freq, quantity, 0, 0);
    }
};
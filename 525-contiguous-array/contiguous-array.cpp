class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n+1,0);
        int ans = 0;
        unordered_map<int,int> mp;
        mp[0] = 0;
        for(int i=1;i<=n;i++) {
            if(!nums[i-1])  prefix[i] = prefix[i-1] - 1;
            else  prefix[i] = prefix[i-1] + 1;
            // cout << prefix[i] << endl;
            if(mp.find(prefix[i]) != mp.end()) {
                ans = max(ans, i - mp[prefix[i]]);
            }
            else {
                mp[prefix[i]] = i;
            }
        }
        return ans;

        return ans;
    }
};
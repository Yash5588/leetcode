class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                mp[nums[i] & nums[j]]++;
            }
        }
        int ans = 0;
        for(auto &[key,value] : mp) {
            for(auto &x : nums) {
                if((x & key) == 0) ans += value; 
            }
        }
        return ans;
    }
};
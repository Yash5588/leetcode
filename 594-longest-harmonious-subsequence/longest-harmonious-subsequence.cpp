class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> count,dp;
        for(int i = 0;i < n;i++) {
            count[nums[i]]++;
        }
        int ma = 0;
        for(auto &[key,val] : count) {
            if(count.find(key-1) != count.end()) {
                ma = max(ma, val + count[key-1]);
            }
        }
        return ma;
    }
};
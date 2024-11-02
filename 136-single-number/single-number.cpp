class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int xorV = 0;
        for(auto &x : nums) xorV ^= x;
        return xorV;
    }
};
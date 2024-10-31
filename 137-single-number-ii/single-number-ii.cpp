class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> bits(32,0);
        for(auto &x : nums) {
            for(int i = 0;i < 32;i++) {
                if(x & (1<<i)) bits[i]++;
            }
        }
        int res = 0;
        for(int i = 0;i < 32;i++) {
            if(bits[i]%3 == 1) {
                res |= (1<<i);
            }
        }
        return res;
    }
};
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorV = 0;
        for(auto &x : nums) {
            xorV ^= x;
        }
        int pos = 0;
        for(int i = 0;i < 32;i++) {
            if(xorV & (1<<i)) {
                pos = i;
                break;
            }
        }
        int set_xor = 0,null_xor = 0;
        for(auto  &x : nums) {
            if(x & (1<<pos)) set_xor^=x;
            else null_xor ^=x;
        }
        return {set_xor,null_xor};
    }
};
class Solution {
public:
    int getSum(int a, int b) {
        int ans = 0;
        int carry = 0;
        for(int i = 0;i < 32;i++) {
            if((a & (1 << i)) && (b & (1 << i))) {
                if(carry) ans |= (1 << i);
                carry = 1;
            }
            else if((a & (1 << i)) || (b & (1 << i))) {
                if(!carry) ans |= (1 << i);
                else {
                    carry = 1;
                }
            }
            else {
                if(carry) {
                    ans |= (1 << i);
                    carry = 0;
                }
            }
        }
        return ans;
    }
};
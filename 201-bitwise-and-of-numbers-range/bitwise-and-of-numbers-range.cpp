class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int res = 0;
        int cnt= 0;
        for(int i = 0;i < 32;i++) {
            if(left == right) {
                res = left;
                break;
            }
            left >>= 1;
            right >>= 1;
            cnt++;
        }
        return res << cnt;
    }
};
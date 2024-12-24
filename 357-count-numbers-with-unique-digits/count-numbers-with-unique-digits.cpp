class Solution {
public:
    int getPermutations(int digits) {
        int val = 9;
        int temp = 9;
        for(int i = 0;i < digits-1;i++) {
            val *= temp;
            temp--;
        }
        return val;
    }
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        if(n == 1) return 10;
        int res = 10;
        for(int i = 2;i <= n;i++) {
            res += getPermutations(i);
        }
        return res;
    }
};
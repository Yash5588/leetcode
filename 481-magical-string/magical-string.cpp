class Solution {
public:
    int magicalString(int n) {
        string str;
        if(n <= 3) return 1;
        str += "122";
        int i = 2,j = 2;
        while(j < n-1) {
            if(str[i] == '1') {
                str += (('3' - str[j]) + '0');
                j++;
            }
            else {
                str += (('3' - str[j]) + '0');
                j++;
                if(j >= n-1) break;
                str += (('3' - str[j-1]) + '0');
                j++;
            }
            i++;
        }
        return count(str.begin(),str.end(),'1');
    }
};
class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int n = str.length();
        int ma = num;
        string temp = str;
        for(int i = 0;i < n-1;i++) {
            for(int j = i+1;j < n;j++) {
                if(str[i] < str[j]) {
                    swap(str[i],str[j]);
                    ma = max(ma, stoi(str));
                    str = temp;
                }
            }
        }
        return ma;
    }
};
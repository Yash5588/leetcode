class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int n = s.length();
        int ans = 0;
        for(auto &str: words) {
            int m = str.length();
            int i = 0,j = 0;
            bool flag = true;
            while(j < m) {
                int count1 = 0,count2 = 0;
                while(j < m && s[i] == str[j]) {
                    j++;
                    count2++;
                }
                if(count2 == 0) {
                    flag = false;
                    break;
                }
                while(i < n && s[i] == str[j-1]) {
                    i++;
                    count1++;
                }
                if(count1 > count2) {
                    if(count1 < 3) {
                        flag = false;
                        break;
                    }
                }
                if(count1 < count2) {
                    flag = false;
                    break;
                }
            }
            if(i == n && j == m && flag) ans++;
        }
        return ans;
    }
};
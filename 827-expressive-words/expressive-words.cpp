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
                //check each group count
                int count1 = 0,count2 = 0;
                while(j < m && s[i] == str[j]) {
                    j++;
                    count2++;
                }
                //if nothing matches break
                if(count2 == 0) {
                    flag = false;
                    break;
                }
                //move other pointer also
                while(i < n && s[i] == str[j-1]) {
                    i++;
                    count1++;
                }
                //compare that group count from both strings
                if(count1 > count2) {
                    if(count1 < 3) {
                        //if it is less than 3 break
                        flag = false;
                        break;
                    }
                }
                if(count1 < count2) {
                    //if main string count is less than words strings break
                    flag = false;
                    break;
                }
            }
            //if both strings reached end and also satisfies all conditions
            //then consider that string in ans
            if(i == n && j == m && flag) ans++;
        }
        return ans;
    }
};
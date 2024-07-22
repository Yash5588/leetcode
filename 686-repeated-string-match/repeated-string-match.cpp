class Solution {
public:
    vector<int> zfunc(string &s, string &b) {
        string str = b + '#' + s;
        int left=0,right = 0;
        vector<int> z(str.size(),0);
        for(int i=1;i<str.size();i++) {
            if(i > right) {
                left = right = i;
                while(right < str.size() && str[right] == str[right-left]) {
                    right++;
                }
                z[i] = right - left;
                right--;
            }
            else {
                int ind = i - left;
                if(i+z[ind] <= right) {
                    z[i] = z[ind];
                }
                else {
                    left = i;
                    while(right < str.size() && str[right] == str[right-left]) {
                        right++;
                    }
                    z[i] = right-left;
                    right--;
                }
            }
        }
        return z;
    }
    int repeatedStringMatch(string a, string b) {
        if(a == b) return 1;
        string str = a;
        int n = a.length(),m = b.length();
        for(int i=0;i<=m/n;i++) {
            str += a;
        }
        vector<int> z = zfunc(str,b);
        for(int i=0;i<z.size();i++) {
            if(z[i] == m) {
                return (i-1)%n ? (i-1)/n+1 : (i-1)/n;
            }
        }
        return -1;
    }
};
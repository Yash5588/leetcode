class Solution {
public:
    vector<long long> zfunc(string &str) {
        long long n = str.length();
        long long left = 0,right = 0;
        vector<long long> z(n,0);
        for(int i = 1;i < n;i++) {
            if(i > right) {
                left = right = i;
                while(right < n && str[right] == str[right - left]) {
                    right++;
                }
                z[i] = right - left;
                right--;
            }
            else {
                long long ind = i - left;
                if(i + z[ind] <= right) z[i] = z[ind];
                else {
                    left = i;
                    while(right < n && str[right] == str[right - left]) {
                        right++;
                    }
                    z[i] = right - left;
                    right--;
                }
            }
        }
        return z;
    }
    long long sumScores(string s) {
        long long n = s.length();
        vector<long long> z = zfunc(s);
        long long score = n;
        for(auto &x : z) score += x;
        return score;
    }
};
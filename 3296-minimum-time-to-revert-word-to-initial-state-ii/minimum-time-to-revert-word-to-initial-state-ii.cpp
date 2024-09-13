class Solution {
public:
    vector<int> zfunc(string &str) {
        int n = str.length();
        int left = 0,right = 0;
        vector<int> z(n,0);
        for(int i = 1;i < n;i++) {
            if(i > right) {
                left = right = i;
                while(right < n && str[right] == str[right - left]) right++;
                z[i] = right - left;
                right--;
            }
            else {
                int ind = i - left;
                if(i + z[ind] <= right) z[i] = z[ind];
                else {
                    left = i;
                    while(right < n && str[right] == str[right - left]) right++;
                    z[i] = right - left;
                    right--; 
                }
            }
        }
        return z;
    }
    int minimumTimeToInitialState(string word, int k) {
        int n = word.size();
        vector<int> z = zfunc(word);
        int c = 0,i;
        for(i = 0;i < n;i+=k) {
            if(z[i] == n - i) {
                break;
            }
            c++;
        }
        if(i > n) {
            return (n % k == 0) ? n/k : n/k+1;
        }
        return c;
    }
};
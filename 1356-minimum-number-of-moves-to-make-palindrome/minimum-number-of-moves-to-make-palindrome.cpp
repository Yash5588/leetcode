class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n = s.length();
        int i = 0,j = n-1,mid = -1;
        int ans = 0;
        while(i < j) {
            int k = j;
            while(k > i && s[k] != s[i]) {
                k--;
            }
            if(k != i) {
                ans += (j - k);
                for(int l=k;l<j;l++) {
                    s[l] = s[l+1];
                }
                s[j] = s[i];
                i++;
                j--;
            }
            else {
                mid = i;
                i++;
            }
        }
        if(mid != -1) {
            ans += (n/2 - mid);
        }
        return ans;
    }
};
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int> one(n),zero(n);
        one[0] = (s[0] == '1');
        zero[0] = (s[0] == '0');
        for(int i=1;i<n;i++) {
            zero[i] = zero[i-1] + (s[i] == '0');
            one[i] = one[i-1] + (s[i] == '1');
        }
        int c = 0, o = 0, z= 0;
        for(int i=0;i<n;i++) {
            for(int j=i;j<n;j++) {
                o = one[j];
                z = zero[j];
                if(i != 0) {
                    o -= one[i-1];
                    z -= zero[i-1];
                }
                if(z*z > o) {
                    j += (z*z - o - 1);
                }
                else {
                    c++;
                    int oneroot = int(sqrt(o));
                    if(j + oneroot-z >= n) c += n-j-1;
                    else c += (oneroot-z);
                    j += (oneroot - z);
                }
            }
        }
        return c;
        
    }
};
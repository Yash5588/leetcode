class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int n = a.length();
        int m = b.length();
        int i = n,j = m;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        for(int i = 0;i < n-m;i++) {
            b += '0';
        }
        for(int i = 0;i < m-n;i++) {
            a += '0';
        }
        n = a.length();
        cout << a << ' ' << b << endl;
        int carry = 0;
        for(int i = 0;i < n;i++) {
            if(a[i] == b[i]) {
                if(a[i] == '1') {
                    if(carry) res += '1';
                    else res += '0';
                    carry = 1;
                }
                else {
                    if(carry) res += '1';
                    else res += '0';
                    carry = 0;
                }
            }
            else {
                if(carry) res += '0';
                else res += '1';
            }
        }
        if(carry) res += '1';
        reverse(res.begin(),res.end());
        return res;
    }
};
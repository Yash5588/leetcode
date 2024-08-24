class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i=0,j=1,k=0;
        if(n == 1) return 1;
        bool flag = false;
        if(chars[n-1] != chars[n-2]) flag = true; 
        while(j < n) {
            chars[k] = chars[i];
            while(j < n && chars[i] == chars[j]) {
                j++;
            }
            k++;
            if(j-i != 1) {
                string str = to_string(j-i);
                for(auto &x : str) {
                    chars[k] = x;
                    k++;
                }
            }
            i = j;
            j++;
        }
        if(flag) {
            chars[k] = chars.back();
            k++;
        }
        return k;
    }
};
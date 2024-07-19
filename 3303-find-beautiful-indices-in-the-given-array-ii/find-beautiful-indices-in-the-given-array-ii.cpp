class Solution {
public:
    vector<int> kmp(string &s, string &pattern) {
        string str = pattern + "#" + s;
        int lpsize = pattern.length() + s.length() + 1;
        vector<int> lps(lpsize,0);
        for(int i=1;i<lpsize;i++) {
            int prev_index = lps[i-1];
            while(prev_index > 0 && str[i] != str[prev_index]) {
                prev_index = lps[prev_index-1];
            }
            lps[i] = prev_index + (str[i] == str[prev_index]);
        }
        return lps;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n = s.length();
        int alen = a.length(), blen = b.length();
        vector<int> ind1, ind2;
        vector<int> lps = kmp(s,a);
        for(int i=0;i<lps.size();i++) {
            if(lps[i] == alen) ind1.push_back(i-2*alen);
        }
        lps = kmp(s,b);
        for(int i=0;i<lps.size();i++) {
            if(lps[i] == blen) ind2.push_back(i-2*blen);
        }
        vector<int> ans;
        for(auto &x : ind1) {
            int low = 0, high = ind2.size()-1;
            while(low <= high) {
                int mid = low + (high - low)/2;
                if(ind2[mid] >= x-k && ind2[mid] <= x+k) {
                    ans.push_back(x);
                    break;
                }
                else if(x+k < ind2[mid]) {
                    high = mid-1;
                }
                else {
                    low = mid+1;
                }
            }
        }
        return ans;
    }
};
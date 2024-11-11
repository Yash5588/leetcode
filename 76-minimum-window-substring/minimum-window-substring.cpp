class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> freq;
        int n = s.length();
        for(auto &x : t) {
            freq[x]++;
        }
        int cnt = 0;
        int mi = INT_MAX;
        int start_ind = -1;
        int first = 0,last = 0;
        int tar_len = freq.size();
        while(last < n) {
            freq[s[last]]--;
            if(freq[s[last]] == 0) {
                cnt++;
            }
            while(first <= last && cnt == tar_len) {
                if(last - first + 1 < mi) {
                    mi = last - first + 1;
                    start_ind = first;
                }
                freq[s[first]]++;
                if(freq[s[first]] > 0) {
                    cnt--;
                }
                first++;
            }
            last++;
        }
        return (mi == INT_MAX) ? "" : s.substr(start_ind,mi);
    }
};
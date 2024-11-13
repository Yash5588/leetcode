class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int first = 0,last = 0;
        vector<int> freq(26,0);
        int max_freq = 0;
        int max_len = 0;
        while(first < n && first <= last) {
            while(last < n) {
                freq[s[last]-'A']++;
                int len = last - first + 1;
                max_freq = max(max_freq, freq[s[last]-'A']);
                if(k < len - max_freq) {
                    freq[s[last]-'A']--;
                    break;
                }
                max_len = max(max_len, len);
                last++;
            }
            // cout << first << ' ' << last << endl;
            // cout << max_len << endl << endl;
            freq[s[first]-'A']--;
            max_freq = *max_element(freq.begin(), freq.end());
            // cout << max_freq << endl;
            first++;
        }
        return max_len;
    }
};
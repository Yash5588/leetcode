class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();
        stack<char> sta;
        vector<int> freq(26,0);
        vector<bool> visited(26,false);
        for(auto &ch : s) {
            freq[ch - 'a']++;
        }
        for(int i = 0;i < n;i++) {
            freq[s[i] - 'a']--;
            if(visited[s[i] - 'a']) continue;
            while(!sta.empty() && sta.top() >= s[i] && freq[sta.top() - 'a'] > 0) {
                visited[sta.top() - 'a'] = false;
                sta.pop();
            }
            sta.push(s[i]);
            visited[s[i]-'a'] = true;
        }
        string res;
        while(!sta.empty()) {
            res += sta.top();
            sta.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
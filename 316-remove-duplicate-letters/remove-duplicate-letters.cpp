class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> freq;
        for(auto &ch : s) {
            freq[ch]++;
        }
        int n = s.length();
        stack<char> sta;
        vector<bool>visited(26,false);
        for(int i=0;i<n;i++) {
            if(!visited[s[i]-'a']) {
                while(!sta.empty() && sta.top()>s[i] && freq[sta.top()] > 0) {
                    visited[sta.top()-'a'] = false;
                    sta.pop();
                }
                sta.push(s[i]);
                freq[s[i]]--;
                visited[s[i]-'a'] = true;
            }
            else {
                freq[s[i]]--;
            }
        }
        string ans;
        while(!sta.empty())  {
            ans += sta.top();
            sta.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
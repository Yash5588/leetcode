class Solution {
public:
    string removeKdigits(string s, int k) {
        int n = s.length();
        if(k >= n) return "0";
        stack<char> sta;
        //check for peacks means that we need to check previous bigger elements and our
        //aim is to make the number in increasing order we'll remove unecessary peaks
        for(int i=0;i<n;i++) {
            while(!sta.empty() && sta.top() > s[i] && k>0) {
                sta.pop();
                k--;
            }
            if(sta.empty() && s[i] == '0') continue;
            sta.push(s[i]);
        }
        if(sta.empty()) return "0";
        string ans;
        while(!sta.empty()) {
            ans += sta.top();
            sta.pop();
        }
        reverse(ans.begin(),ans.end());
        //the number is increasing but k is not zero this is to handle that case
        int m = ans.size();
        if(k >= m) return "0";
        return ans.substr(0,m-k);
    }
};
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        if(n <= 10) return {};
        unordered_map<string,int> count;
        string str = s.substr(0,10);
        count[str]++;
        vector<string> ans;
        for(int i=0;i<n-10;i++) {
            str.erase(str.begin());
            str += s[i+10];
            if(count[str] != -1) {
                count[str]++;
            }
            if(count[str] > 1) {
                ans.push_back(str);
                count[str] = -1;
            }
        }
        return ans;
    }
};
class Solution {
public:
    static bool sortIfEqual(vector<int> &a, vector<int> &b) {
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(),envelopes.end(),sortIfEqual);
        vector<int> lis_len;
        for(int i = 0;i < n;i++) {
            int ind = lower_bound(lis_len.begin(),lis_len.end(),envelopes[i][1]) - lis_len.begin();
            if(ind == lis_len.size()) lis_len.push_back(envelopes[i][1]);
            else lis_len[ind] = envelopes[i][1];
        }
        return lis_len.size();
    }
};
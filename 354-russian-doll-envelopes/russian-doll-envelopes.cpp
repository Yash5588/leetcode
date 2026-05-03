class Solution {
public:
    static bool sortBySec(vector<int> &a, vector<int> &b) {
        if(a[1] == b[1]) return a[0] > b[0];
        return a[1] < b[1];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),sortBySec);
        vector<int> vec;
        int n = envelopes.size();
        for(int i = 0;i < n;i++) {
            int idx = lower_bound(vec.begin(),vec.end(),envelopes[i][0]) - vec.begin();
            if(idx == vec.size()) {
                vec.push_back(envelopes[i][0]);
            }
            else vec[idx] = envelopes[i][0];
        }
        return vec.size();
    }
};
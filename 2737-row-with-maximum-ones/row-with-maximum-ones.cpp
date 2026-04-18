class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        for(auto &x : mat) {
            sort(x.begin(),x.end());
        }
        int mxm = INT_MIN;
        int num = 0;
        int c= 0;
        for(auto &row : mat) {
            int idx = lower_bound(row.begin(),row.end(),1) - row.begin();
            int cnt = row.size() - idx;
            if(mxm < cnt) {
                mxm = cnt;
                num = c;
            }
            c++;
        }
        return {num,mxm};
    }
};
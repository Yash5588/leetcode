class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int low = 0, high = m-1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            int mxm = INT_MIN, mxm_idx = 0;
            for(int i = 0;i < n;i++) {
                if(mxm < mat[mid][i]) {
                    mxm = mat[mid][i];
                    mxm_idx = i;
                }
            }
            int top = (mid == 0) ? -1 : mat[mid-1][mxm_idx];
            int bottom = (mid == m-1) ? -1 : mat[mid+1][mxm_idx];
            if(mxm > top && mxm > bottom) return {mid,mxm_idx};
            if(mxm < top) high = mid - 1;
            else low = mid + 1;
        }
        return {0,0};
    }
};
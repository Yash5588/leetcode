class Solution {
public:
    int Algo(vector<int> &arr, int k) {
        int sum = 0, ma = INT_MIN;
        set<int> se;
        se.insert(0);
        for(int i=0;i<arr.size();i++) {
            sum += arr[i];
            set<int> ::iterator iter = se.lower_bound(sum-k);
            if(iter != se.end()) {
                ma = max(ma, sum-*iter);
            }
            se.insert(sum);
        }
        return ma;
    }
    int maxSumSubmatrix(vector<vector<int>>& a, int k) {
        int row = a.size();
        int col = a[0].size();
        int ma = INT_MIN;
        for(int i=0;i<row;i++) {
            vector<int> colSum(col);
            for(int j=i;j<row;j++) {
                for(int c=0;c<col;c++) {
                    colSum[c] += a[j][c];
                }
                ma = max(ma, Algo(colSum,k));
            }
        }
        return ma;
    }
};
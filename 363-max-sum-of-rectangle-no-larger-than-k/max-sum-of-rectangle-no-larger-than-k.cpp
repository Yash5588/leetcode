class Solution {
public:
  int find(vector<int>& sum, int k) {
    int result = INT_MIN;
    set<int> se;
    se.insert(0);
    int prefixSum = 0;
    for(int i = 0; i < sum.size(); i++) {
      prefixSum += sum[i];

      set<int>::iterator target = se.lower_bound(prefixSum - k);

      if(target != se.end()) {
        result = max(result, prefixSum - *target);
      }
      se.insert(prefixSum);
    }

    return result;
  }
  //Time: O(r2 * clogc)
  // SC : O(c)
  int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
    int row = matrix.size();
    int col = matrix[0].size();
    int ma = INT_MIN;
    for (int i = 0; i < row; i ++) {
      vector<int> colSum(col,0);
      for (int j = i; j < row; j ++) {
        for (int c = 0; c < col; c ++) {
          colSum[c] += matrix[j][c];
          //System.out.print(colSum[c] + " ");
        }
        //System.out.println();
        ma = max(ma, find(colSum, k));
      }
    }
    return ma;
  }
};
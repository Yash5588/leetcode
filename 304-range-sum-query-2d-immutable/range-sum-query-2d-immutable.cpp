class NumMatrix {
public:
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        prefix = matrix;
        int m = matrix.size();
        int n = matrix[0].size();
        //calculate prefix sum of matrix
        for(int i=1;i<m;i++) {
            prefix[i][0] += prefix[i-1][0];
        }
        for(int j=1;j<n;j++) {
            prefix[0][j] += prefix[0][j-1];
        }
        //subtract diagonal becoz is added 2 times 
        for(int i=1;i<m;i++) {
            for(int j=1;j<n;j++) {
                prefix[i][j] += prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 == 0 && col1 == 0) return prefix[row2][col2];
        if(row1 == 0) return prefix[row2][col2] - prefix[row2][col1-1];
        if(col1 == 0) return prefix[row2][col2] - prefix[row1-1][col2];
        // add diagonal becoz it is subtracted 2 times
        return prefix[row2][col2] - prefix[row1-1][col2] - prefix[row2][col1-1] + prefix[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
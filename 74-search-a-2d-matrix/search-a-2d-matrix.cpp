class Solution {
public:
    bool search(vector<int> &row, int target) {
        return binary_search(row.begin(),row.end(),target);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0, high = n-1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(search(matrix[mid],target)) {
                return true;
            }
            else if(target < matrix[mid][0]) {
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return false;
    }
};
class Solution {
public:
    //how to smallest elements count?
    //we know that each row is sorted
    //so in each row apply lower bound for that particular element
    //store lesser count in total
    int getCount(vector<vector<int>> &matrix, int ele) {
        int n = matrix.size();
        int count = 0;
        for(int row = 0;row < n;row++) {
            count += upper_bound(matrix[row].begin(),matrix[row].end(),ele) - matrix[row].begin();
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        //apply lower bound on result
        //starting element is min and last element in matrix is max
        int low = matrix[0][0],high = matrix[n-1][n-1];
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            //store result and opt for better result in due process
            if(getCount(matrix,mid) >= k) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};
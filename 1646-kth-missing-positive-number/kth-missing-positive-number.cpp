class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size()-1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(arr[mid] - (mid+1) < k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        if(high < 0) return k;
        int missing = arr[high] - (high + 1);
        return arr[high] + (k - missing);
    }
};
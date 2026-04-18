class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        int mnm = INT_MAX;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(nums[low] <= nums[mid]) {
                mnm = min(mnm, nums[low]);
                low = mid + 1;
            }
            else {
                mnm = min(mnm, nums[mid]);
                high = mid - 1;
            }
        }
        return mnm;
    }
};
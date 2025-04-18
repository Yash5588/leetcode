class Solution {
public:
    bool isPossible(vector<int> &nums, int maxOperations, int mid) {
        int operations = 0;
        int n = nums.size();
        for(int i = 0;i < n;i++) {
            //this is the bag division if we want to attain the min result as mid
            if(nums[i] > mid) {
                operations += (nums[i] % mid == 0) ? (nums[i]/mid)-1 : nums[i]/mid; 
            }
        }
        //if those operations to make it as min is less then maxOperations
        //then we can form it as min otherwise it is not possible
        return operations <= maxOperations;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();
        int low = 1,high = 1e9+7;
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            //if satisfies then try to minimize the result
            if(isPossible(nums,maxOperations,mid)) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};
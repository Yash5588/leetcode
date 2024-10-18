class Solution {
public:
    bool canFormGroups(vector<int> nums, int req) {
        int accumulated = 0;
        int n = nums.size();
        for(int i = 0;i < n;i++) {
            if(nums[i] >= req) {
                nums[i] -= req;
                if(accumulated > 0) {
                    accumulated -= nums[i];
                }
            }
            else {
                accumulated += (req - nums[i]);
            }
            if(req > 0) req--;
        }
        return accumulated <= 0;
    }
    int maxIncreasingGroups(vector<int>& nums) {
        int n = nums.size();
        int low = 1,high = n;
        int res = -1;
        sort(nums.begin(),nums.end(),greater<int>());
        // cout << canFormGroups(nums,2) << endl;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(canFormGroups(nums,mid)) {
                res = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return res;
    }
};
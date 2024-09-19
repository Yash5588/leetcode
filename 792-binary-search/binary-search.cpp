class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int ind = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        if(ind < n && nums[ind] == target) return ind;
        return -1;

    }
};
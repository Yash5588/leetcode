class Solution {
public:
    bool solve(vector<int> &nums, int k, int pos, int target, long long sum, int mask) {
        int n = nums.size();
        if(k == 0) {
            return true;
        }
        if(sum == target) {
            //one subset sum is found find rest subsets by keeping mask intact
            //from the start of the array
            return solve(nums, k-1, 0, target, 0, mask);
        }
        if(sum > target) return false;
        for(int i = pos;i < n;i++) {
            if(mask & (1 << i)) continue;
            if(solve(nums, k, i, target, sum + nums[i], mask | (1 << i))) return true;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum % k != 0) return false;
        vector<bool> taken(n, false);
        return solve(nums, k, 0, sum/k, 0, 0);
    }
};
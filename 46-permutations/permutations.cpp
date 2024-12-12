class Solution {
public:
    vector<vector<int>> res;
    void solve(vector<int> &nums, vector<int> temp, int mask) {
        int n = nums.size();
        if(temp.size() >= n) {
            res.push_back(temp);
            return;
        }
        for(int i = 0;i < n;i++) {
            if(mask & (1 << i)) continue;
            temp.push_back(nums[i]);
            solve(nums, temp, mask | (1<<i));
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        solve(nums, {}, 0);
        return res;
    }
};
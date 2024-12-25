class Solution {
public:
    vector<vector<int>> res;
    set<vector<int>> se;
    void backtrack(vector<int> &nums, int prevInd, int mask, vector<int> &temp) {
        int n = nums.size();
        if(temp.size() >= 2) {
            if(se.find(temp) == se.end()) {
                res.push_back(temp);
                se.insert(temp);
            }
        }
        for(int i = 0;i < n;i++) {
            if(mask & (1 << i)) continue;
            if(prevInd == -101 || (i > prevInd && nums[i] >= nums[prevInd])) {
                temp.push_back(nums[i]);
                backtrack(nums, i, mask | (1 << i), temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        backtrack(nums, -101, 0, temp);
        return res;
    }
};
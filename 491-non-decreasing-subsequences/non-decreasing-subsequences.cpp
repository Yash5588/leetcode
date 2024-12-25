class Solution {
public:
    set<vector<int>> res;
    void backtrack(vector<int> &nums, int pos, vector<int> &temp) {
        int n = nums.size();
        if(temp.size() >= 2) {
            if(res.find(temp) == res.end()) {
                res.insert(temp);
            }
        }
        for(int i = pos+1;i < n;i++) {
            if(nums[i] >= nums[pos]) {
                temp.push_back(nums[i]);
                backtrack(nums, i, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        int n = nums.size();
        for(int i = 0;i < n;i++) {
            temp.push_back(nums[i]);
            backtrack(nums, i, temp);
            temp.pop_back();
        }
        return vector<vector<int>> (res.begin(),res.end());
    }
};
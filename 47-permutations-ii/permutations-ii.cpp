class Solution {
public:
    set<vector<int>> se;
    void solve(vector<int> &nums, vector<int> temp, int mask) {
        int n = nums.size();
        if(temp.size() >= n) {
            se.insert(temp);
            return;
        }
        for(int i = 0;i < n;i++) {
            if(mask & (1 << i)) continue;
            temp.push_back(nums[i]);
            solve(nums,temp,mask | (1 << i));
            temp.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        solve(nums,{},0);
        return vector<vector<int>> (se.begin(),se.end());
    }
};
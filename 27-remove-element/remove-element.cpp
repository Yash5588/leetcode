class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            if(nums[i] != val) {
                ans.push_back(nums[i]);
            }
        }
        for(int i=0;i<ans.size();i++) nums[i] = ans[i];
        return ans.size();
    }
};
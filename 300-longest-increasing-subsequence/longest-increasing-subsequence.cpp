class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec;
        for(int i = 0;i < n;i++) {
            int ind = lower_bound(vec.begin(),vec.end(),nums[i]) - vec.begin();
            if(ind == vec.size()) vec.push_back(nums[i]);
            else vec[ind] = nums[i];
        }
        return vec.size();
    }
};
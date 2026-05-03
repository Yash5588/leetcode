class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> vec;
        int n = nums.size();
        for(int i = 0;i < n;i++) {
            int ind = lower_bound(vec.begin(),vec.end(),nums[i]) - vec.begin();
            if(ind == vec.size()) vec.push_back(nums[i]);
            else vec[ind] = nums[i];
        }
        return vec.size();
    }
};
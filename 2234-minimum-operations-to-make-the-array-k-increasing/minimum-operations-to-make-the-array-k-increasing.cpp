class Solution {
public:
    int LIS(vector<int> &nums, int startPos, int k) {
        int n = nums.size();
        vector<int> vec;
        int total = 0;
        for(int i = startPos;i < n;i += k) {
            int ind = upper_bound(vec.begin(),vec.end(),nums[i]) - vec.begin();
            if(ind == vec.size()) vec.push_back(nums[i]);
            else vec[ind] = nums[i];
            total++;
        }
        //remaining we need to change to get min operations
        return total - vec.size();
    }
    int kIncreasing(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        for(int i = 0;i < k;i++) {
            //longest non decreasing subsequence
            int needToChange = LIS(nums, i, k);
            res += needToChange;
        }
        return res;
    }
};
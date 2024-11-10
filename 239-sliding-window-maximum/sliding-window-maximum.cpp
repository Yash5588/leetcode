class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int,greater<int>> se;
        vector<int> res;
        int n = nums.size();
        for(int i = 0;i < k;i++) {
            se.insert(nums[i]);
        }
        res.push_back(*se.begin());
        for(int i = 0;i < n-k;i++) {
            se.erase(se.find(nums[i]));
            se.insert(nums[i+k]);
            res.push_back(*se.begin());
        }
        return res;
    }
};
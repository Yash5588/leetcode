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
            //se.erase() removes all occurances
            //to remove single occurance we use find which returns the iterator
            se.erase(se.find(nums[i]));
            se.insert(nums[i+k]);
            res.push_back(*se.begin());
        }
        return res;
    }
};
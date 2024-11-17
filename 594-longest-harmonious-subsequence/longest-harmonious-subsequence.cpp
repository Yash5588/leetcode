class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int first = 0,last = 0;
        int ma = 0;
        while(first <= last) {
            while(last < n && nums[last]-nums[first] == 0) {
                last++;
            }
            while(last < n && nums[last]-nums[first] == 1) {
                last++;
                ma = max(ma, last-first);
            }
            // ma = max(ma, last-first);
            first++;
        }
        return ma;
    }
};
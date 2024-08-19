class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int first = 0,last = n-1;
        while(first < last) {
            while(first < last && nums[last] == val) {
                last--;
            }
            if(first < last && nums[first] != val) {
                first++;
            }
            if(first < last) {
                swap(nums[first],nums[last]);
            }
        }
        if(last >= 0 && nums[last] == val) return 0;
        return last+1;
    }
};
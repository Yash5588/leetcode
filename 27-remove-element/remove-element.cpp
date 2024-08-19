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
        //for empty array and if array contains all elements as val ex: [2,2,2] val = 2 edge case
        if(last >= 0 && nums[last] == val) return 0;
        return last+1;
    }
};
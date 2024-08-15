class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int flips = 0;
        for(int i=0;i<n;i++) {
            if(nums[i] == 0 && flips%2 == 0) {
                flips++;
            }
            else if(nums[i] == 1 && flips%2 != 0) {
                flips++;
            }
        }
        return flips;
    }
};
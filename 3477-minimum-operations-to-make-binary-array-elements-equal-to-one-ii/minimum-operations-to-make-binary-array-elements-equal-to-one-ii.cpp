class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int flips = 0;
        //keep track of all previous splits
        for(int i=0;i<n;i++) {
            //if current bit is '0' and previous flips are even then the bit will remain same to avoid that we will perform one more flip
            if(nums[i] == 0 && flips%2 == 0) {
                flips++;
            }

            //if current bit is '1' and previous flips are odd then 1 changes to 0 we don't need that so flip it
            else if(nums[i] == 1 && flips%2 != 0) {
                flips++;
            }
        }
        return flips;
    }
};
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;
        //for next permutation we need a break point
        //such that it should be less than next element
        //specifically find that point from last
        for(int i=n-2;i>=0;i--) {
            //check with next element
            if(nums[i] < nums[i+1]) {
                ind = i;
                break;
            }
        }
        //checking if there is no break point(decreasing array)
        if(ind != -1) {
            //swap with greater element such that it should be smallest and it should be greater than break point index
            for(int i=n-1;i>ind;i--) {
                if(nums[ind] < nums[i]) {
                    //if you find swap them
                    swap(nums[i],nums[ind]);
                    break;
                }
            }
        }
        //anyway after break point we observe that it is sorted in decreasing order
        //we need it the smallest
        // we need it in ascending order so we reverse it
        reverse(nums.begin()+ind+1,nums.end());
    }
};
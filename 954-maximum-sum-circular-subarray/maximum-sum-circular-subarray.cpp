class Solution {
public:
    //kadane's algo
    int maxSubarraySum(vector<int> &nums) {
        int n = nums.size();
        int sum = nums[0];
        int ma = nums[0];
        for(int i = 1;i < n;i++) {
            sum = max(sum+nums[i],nums[i]);
            ma = max(ma, sum);
        }
        return ma;
    }
    //reverse kadane's algo
    int minSubarraySum(vector<int> &nums) {
        int n = nums.size();
        int sum = nums[0];
        int mi = nums[0];
        for(int i = 1;i < n;i++) {
            sum = min(sum+nums[i],nums[i]);
            mi = min(mi, sum);
        }
        return mi;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
       int n = nums.size();
       int total = accumulate(nums.begin(),nums.end(),0);
       int maxSum = maxSubarraySum(nums); 
       int minSum = minSubarraySum(nums);
       int circularSum = total - minSum;
       //there is no positive element in array
       if(maxSum < 0) return *max_element(nums.begin(),nums.end());
       return max(maxSum, circularSum);
    }
};
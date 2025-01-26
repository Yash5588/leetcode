class Solution {
public:
    int maxSubarraySum(vector<int> &nums, int k, int val) {
        //take -1 for k and +1 for val and ignore all other elements
        //get max subarray sum
        int sum = 0;
        int ma = 0;
        int n = nums.size();
        for(int i = 0;i < n;i++) {
            if(nums[i] == k) sum--;
            else if(nums[i] == val) sum++;
            if(sum < 0) sum = 0;
            ma = max(ma, sum);
        }
        return ma;
    }
    int maxFrequency(vector<int>& nums, int k) {
        //first of all get the count of k
        int cnt = count(nums.begin(),nums.end(),k);
        int n = nums.size();
        //try out for all possible elements
        int ma = 0;
        for(int i = 1;i <= 50;i++) {
            ma = max(ma, maxSubarraySum(nums,k,i));
        }
        return ma + cnt;
    }
};
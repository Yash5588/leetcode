class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans = 1e9;
        int n = nums.size();
        for(int k=0;k<n-2;k++) {
            int i = k+1,j = n-1;
            while(i < j) {
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(target - sum) < abs(target - ans)) {
                    ans = sum;
                }
                if(sum < target) i++;
                else j--;
            }
        }
        return ans;
    }
};
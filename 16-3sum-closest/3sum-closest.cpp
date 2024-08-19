class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //whenever no index is needed and sum is asked just sort
        //by that we can apply 2-pointer logic there
        sort(nums.begin(),nums.end());
        int ans = 1e9;
        int n = nums.size();
        //fix one pointer
        for(int k=0;k<n-2;k++) {
            //apply 2 pointer logic here
            int i = k+1,j = n-1;
            while(i < j) {
                int sum = nums[i] + nums[j] + nums[k];
                //checking the distance between sum and target and update
                if(abs(target - sum) < abs(target - ans)) {
                    ans = sum;
                }
                //general 2 - pointer algorithm
                if(sum < target) i++;
                else j--;
            }
        }
        return ans;
    }
};
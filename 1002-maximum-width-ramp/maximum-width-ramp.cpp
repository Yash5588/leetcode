class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> sta;
        sta.push(0);
        for(int i=1;i<n;i++) {
            if(nums[sta.top()] >= nums[i]) sta.push(i);  
        }
        int ma = INT_MIN;
        for(int i=n-1;i>=0;i--) {
            while(!sta.empty() && nums[sta.top()] <= nums[i]) {
                ma = max(ma, i-sta.top());
                sta.pop();
            }
        }
        return ma;
    }
};
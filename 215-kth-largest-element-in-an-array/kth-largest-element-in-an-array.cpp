class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int,vector<int>,greater<int>> que;
        for(int i = 0;i < k;i++) {
            que.push(nums[i]);
        }
        for(int i = k;i < n;i++) {
            que.push(nums[i]);
            que.pop();
        }
        return que.top();
    }
};
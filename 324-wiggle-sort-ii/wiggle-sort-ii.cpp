class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int> que;
        for(int i = 0;i < n;i++) que.push(nums[i]);
        int j = 1;
        int k = 0;
        while(!que.empty()) {
            if(j < n) {
                nums[j] = que.top();
                j += 2;
            }
            else {
                nums[k] = que.top();
                k += 2;
            }
            que.pop();
        }
    }
};
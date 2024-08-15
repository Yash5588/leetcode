class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        queue<int> que;
        int ma = INT_MIN;
        for(int i=0;i<n;i++) {
            if(k == 0) {
                ma = 0;
                break;
            }
            if(nums[i] == 0) {
                que.push(i);
                k--;
            }
            if(!k) {
                ma = i+1;
                break;
            }
        }
        if(ma == INT_MIN) return n;
        int sum = ma,prev = -1;
        for(int i=ma;i<n;i++) {
            if(nums[i] == 1) {
                sum++;
                ma = max(ma, sum);
            }
            else {
                if(!que.empty()) {
                    sum -= (que.front() - prev - 1);
                    prev = que.front();
                    que.pop();
                    que.push(i);
                }
                else {
                    sum = 0;
                }
            }
        }
        return ma;
    }
};
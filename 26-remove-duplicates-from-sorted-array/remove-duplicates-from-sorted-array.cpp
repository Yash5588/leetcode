class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        stack<int> sta,sta2;
        for(int i=0;i<n;i++) {
            while(!sta.empty() && sta.top() == nums[i]) {
                sta.pop();
            }
            sta.push(nums[i]);
        }
        while(!sta.empty()) {
            sta2.push(sta.top());
            sta.pop();
        }
        int c= sta2.size();
        for(int i=0;i<c;i++) {
            nums[i] = sta2.top();
            sta2.pop();
        }
        return c;
    }
};
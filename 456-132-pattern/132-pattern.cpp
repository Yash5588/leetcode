class Solution {
public:
    // 1) our main aim is to find the largest 2nd largest and smallest 
    // 2) but we need to take care of indexing largest is somewhere in middle and 2nd largest should be right side of largest and smallest should be left of both
    // 3) we'll iterate from back to keep indexes in order
    // 4) we use stack while we find largest we can find 2nd largest using monotonic stack precisely decreasing\
    // 5) at the end we will compare both the 2nd largest and smallest
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> sta;
        int numk = INT_MIN;
        for(int i=n-1;i>=0;i--) {
            while(!sta.empty() && sta.top() < nums[i]) {
                numk = sta.top();
                sta.pop();
            }
            if(numk > nums[i]) return true;
            sta.push(nums[i]);
        }
        return false;
    }
};
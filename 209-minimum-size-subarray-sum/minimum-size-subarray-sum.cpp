class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n+1,0);
        for(int i=1;i<=n;i++) {
            prefix[i] = prefix[i-1] + nums[i-1];
        }
        int first = 0;
        int mi = INT_MAX;
        for(int last=0;last<=n;last++) {
            while((first<last) && (prefix[last] - prefix[first] >= target)) {
                mi = min(mi, last-first);
                first++;
            }
        }
        if(mi != INT_MAX) return mi;
        return 0;
    }
};
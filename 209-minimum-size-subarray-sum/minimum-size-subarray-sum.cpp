class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        //prefix sum array
        vector<int> prefix(n+1,0);
        for(int i=1;i<=n;i++) {
            prefix[i] = prefix[i-1] + nums[i-1];
        }
        //2-pointer sliding window
        //if sum nums[last] - nums[first] exceeds target then we move first pointer to make it less and we move last pointer to make subarray sum equal to the target.
        int first = 0;
        int mi = INT_MAX;
        for(int last=0;last<=n;last++) {
            while((first<last) && (prefix[last] - prefix[first] >= target)) {
                mi = min(mi, last-first);  //at every increase in 1st pointer size of subarray decreases so we calculate min length of that subarray.
                first++;
            }
        }
        if(mi != INT_MAX) return mi;
        return 0;
    }
};
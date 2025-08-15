class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0, first = 0;
        long long prefix_prod = 1;
        for(int last = 0;last < n;last++) {
            prefix_prod *= nums[last];
            while(first <= last && prefix_prod >= k) {
                prefix_prod /= nums[first];
                first++;
            }
            cnt += (last - first + 1);
        }
        return cnt;
    }
};
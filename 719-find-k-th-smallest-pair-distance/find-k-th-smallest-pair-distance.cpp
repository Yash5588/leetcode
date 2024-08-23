class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> bucket(1000001,0);
        for(int i=0;i<n-1;i++) {
            for(int j=i+1;j<n;j++) {
                bucket[abs(nums[i]-nums[j])]++;
            }
        }
        for(int i=0;i<=1000000;i++) {
            k -= bucket[i];
            if(k <= 0) return i;
        }
        return 0;
    }
};
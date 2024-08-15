class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        long long flips = 0;
        long long ans = 0;
        vector<bool> isFlipped(n+1,false);
        for(int i=0;i<k;i++) {
            if(nums[i] == 0 && flips % 2 == 0) {
                flips++;
                ans++;
                isFlipped[i] = true;
            }
            if(nums[i] == 1 && flips % 2 != 0) {
                flips++;
                ans++;
                isFlipped[i] = true;
            }
        }
        for(int i=0;i<n-k;i++) {
            if(isFlipped[i]) flips--;
            if(nums[i+k] == 0 && flips % 2 == 0) {
                flips++;
                ans++;
                isFlipped[i+k] = true;
            }
            if(nums[i+k] == 1 && flips % 2 != 0) {
                flips++;
                ans++;
                isFlipped[i+k] = true;
            }
        }
        for(int i=n-k+1;i<n;i++) {
            if(isFlipped[i]) return -1;
        }
        return ans;
    }
};
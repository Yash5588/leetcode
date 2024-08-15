class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        //for counting the previous flips for each window
        long long flips = 0;

        //flips in overall array
        long long ans = 0;

        //to keep track which index bit has contributed for flipping so that when window moves we can remove those flips
        vector<bool> isFlipped(n+1,false);

        //building the window
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

        //window is moving remove flips for i and add for i+k becoz of sliding window technique 
        //keep track of overall flips
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

        //This is a zone where we can't apply flipping so from
        //n-k -> n if we need to apply a flip we can't so we can't convert whole 1's in the end see question and understand.
        for(int i=n-k+1;i<n;i++) {
            if(isFlipped[i]) return -1;
        }
        return ans;
    }
};
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int i = k,j = k;
        int mi = nums[k];
        int score = nums[k];
        while(i > 0 && j < n-1) {
            if(nums[i-1] > nums[j+1]) {
                i--;
                mi = min(mi, nums[i]);
            }
            else {
                j++;
                mi = min(mi, nums[j]);
            }
            score = max(score, mi * (j - i + 1));
        }
        while(i > 0) {
            i--;
            mi = min(mi, nums[i]);
            score = max(score, mi * (j - i + 1));
        }
        while(j < n-1) {
            j++;
            mi = min(mi, nums[j]);
            score = max(score, mi * (j - i + 1));
        }
        return score;
    }
};
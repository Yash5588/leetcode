class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n+2,0),suffix(n+2,0);
        //find prefix sum
        for(int i=1;i<=n;i++) {
            prefix[i] = prefix[i-1] + nums[i-1];
        }
        //find suffix sum
        for(int i=n;i>=1;i--) {
            suffix[i] = suffix[i+1] + nums[i-1];
        }
        //for each index check for left and right sum 1-based ind so reduce 1
        for(int i=1;i<=n;i++) {
            if(prefix[i-1] == suffix[i+1]) return i-1;
        }
        return -1;
    }
};
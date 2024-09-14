class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        //dp of type unordered map which stores differences
        vector<unordered_map<long long,long long>> dp(n, unordered_map<long long,long long> ());
        long long res = 0;
        for(int i = 1;i < n;i++) {
            for(int j = 0;j < i;j++) {
                //get the difference
                long long diff = (long long)nums[i] - (long long)nums[j];
                //i and j is a single pair of that difference so add it
                dp[i][diff]++;
                //now get the past results of same differences from
                //previous elements
                //add that same differences subsequences of jth index
                //to ith index
                dp[i][diff] += dp[j][diff];
                //here we are adding jth subsequences
                //becoz if we add ith difference result
                //we are adding length 2 subsequences also
                //so to avoid that we are adding length 3 or more subseqeunces
                //in result
                res += dp[j][diff];
            }
        }
        return res;
    }
};
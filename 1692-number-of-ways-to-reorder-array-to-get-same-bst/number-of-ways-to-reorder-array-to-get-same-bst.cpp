class Solution {
public:
    int mod = 1e9+7;
    long long postorder(vector<int> &nums, vector<vector<long long>> &ncr) {
        int n = nums.size();
        //no element then no rearrangement
        if(n == 0) return 1;
        //left subtree elements and right subtree elements
        vector<int> left, right;
        for(int i = 1;i < n;i++) {
            if(nums[i] < nums[0]) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }
        int r = left.size();
        long long left_arrange = postorder(left,ncr)%mod;
        long long right_arrange = postorder(right,ncr)%mod;
        //formula
        long long res = ((ncr[n-1][r] * left_arrange)%mod * right_arrange)%mod;
        return res;
    }
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        //calculate all possible ncr combinations using dp
        vector<vector<long long>> ncr(n+1,vector<long long> (n+1,1));
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j < i;j++) {
                ncr[i][j] = ((ncr[i-1][j-1])%mod + (ncr[i-1][j])%mod)%mod;
            }
        }
        long long ans = postorder(nums,ncr)%mod;
        // for(int i = 0;i <= n;i++) {
        //     for(int j = 0;j <= i;j++) {
        //         cout << i << ' ' << j << ' ' << ncr[i][j] << endl;
        //     }
        // }
        return ans - 1;
    }
};
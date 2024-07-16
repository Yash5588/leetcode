class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& a, int k) {
        int row = a.size();
        int col = a[0].size();

        //calculate prefix sum for each row
        for(int i=0;i<row;i++) {
            for(int j=1;j<col;j++) {
                a[i][j] += a[i][j-1];
            }
        }

        //then fix columns and iterate over to check sum-k using map;
        int ans = 0;
        for(int start=0;start<col;start++) {
            for(int j=start;j<col;j++) {
                unordered_map<long long, int> mp;
                mp[0] = 1;
                int sum = 0;
                for(int i=0;i<row;i++) {
                    sum += a[i][j] - (start>0 ? a[i][start-1] : 0);
                    ans += mp[sum-k];
                    mp[sum]++;
                }
            }
        }
        return ans;


    }
};
class Solution {
public:
    unordered_map<string,int> dp;
    int solve(vector<int> &arr1, vector<int> &arr2, int pos, int prev) {
        int n = arr1.size();
        int m = arr2.size();
        if(pos >= n) {
            return 0;
        }
        string key = to_string(pos) + '&' + to_string(prev);
        if(dp.find(key) != dp.end()) return dp[key];
        int pick = 1e9+1,not_pick = 1e9+1;
        if(arr1[pos] > prev) {
            not_pick = solve(arr1,arr2,pos+1,arr1[pos]);
        }
        int ind = upper_bound(arr2.begin(),arr2.end(),prev) - arr2.begin();
        if(ind < m) {
            pick = 1 + solve(arr1,arr2,pos+1,arr2[ind]);
        }
        return dp[key] = min(pick,not_pick);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        sort(arr2.begin(),arr2.end());
        int res = solve(arr1,arr2,0,INT_MIN);
        if(res == 1e9+1) return -1;
        return res;
    }
};
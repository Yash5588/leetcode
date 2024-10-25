class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        int n = arr.size();
        vector<unordered_set<int>> sets(n+1);
        int ans = INT_MAX;
        for(int i = 0;i < n;i++) {
            unordered_set<int> prev = sets[i];
            unordered_set<int> curr = sets[i+1];
            curr.insert(arr[i]);
            for(auto &x : prev) {
                curr.insert(x & arr[i]);
            }
            for(auto &x : curr) {
                ans = min(ans, abs(x-target));
            }
            sets[i] = prev;
            sets[i+1] = curr;
        }
        return ans;
    }
};
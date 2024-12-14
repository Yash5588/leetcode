class Solution {
public:
    vector<vector<int>> res;
    void solve(int k, int n, vector<int> store, int prev) {
        if(store.size() >= k) {
            if(n == 0) {
                res.push_back(store);
            }
            return;
        }
        if(n <= 0) {
            return;
        }
        for(int i = prev+1;i <= 9;i++) {
            store.push_back(i);
            solve(k, n - i, store, i);
            store.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        //prev = 0 initially for simplicity
        solve(k, n, {}, 0);
        return res;
    }
};
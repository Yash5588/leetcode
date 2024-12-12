class Solution {
public:
    vector<vector<int>> res;
    void solve(int n, int k, vector<int> temp, int prev) {
        if(temp.size() >= k) {
            res.push_back(temp);
            return;
        }
        for(int i = prev+1;i <= n;i++) {
            temp.push_back(i);
            solve(n,k,temp,i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        solve(n,k,{},0);
        return vector<vector<int>> (res.begin(),res.end());
    }
};
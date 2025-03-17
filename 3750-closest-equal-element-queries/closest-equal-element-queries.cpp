class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int,vector<int>> indices;
        for(int i = 0;i < n;i++) {
            indices[nums[i]].push_back(i);
        }
        vector<int> res;
        for(auto &q : queries) {
            int idx = q;
            int diff = INT_MAX;
            int ele = nums[idx];
            int ind = lower_bound(indices[ele].begin(), indices[ele].end(), idx) - indices[ele].begin();
            int size = indices[ele].size();
            if(size == 1) res.push_back(-1);
            else {
                if(ind == 0) {
                    diff = min(diff, indices[ele][ind+1] - indices[ele][ind]);
                    diff = min(diff, (n - indices[ele].back()) + indices[ele].front());
                }
                else if(ind == size-1) {
                    diff = min(diff, indices[ele][ind] - indices[ele][ind-1]);
                    diff = min(diff, (n - indices[ele].back()) + indices[ele].front());
                }
                else {
                    diff = min(diff, indices[ele][ind] - indices[ele][ind-1]);
                    diff = min(diff, indices[ele][ind+1] - indices[ele][ind]);
                }
                res.push_back(diff);
            }
        }
        return res;
    }
};
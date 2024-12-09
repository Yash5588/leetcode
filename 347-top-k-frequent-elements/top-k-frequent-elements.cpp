class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> count;
        vector<vector<int>> bucket(n+1);
        for(auto &x : nums) count[x]++;
        for(auto &[key,cnt] : count) {
            bucket[cnt].push_back(key);
        }
        vector<int> res;
        int cnt = 0;
        for(int i = n;i >= 0;i--) {
            for(auto &x : bucket[i]) {
                res.push_back(x);
                cnt++;
                if(cnt >= k) break;
            }
            if(cnt >= k) break;
        }
        return res;
    }
};
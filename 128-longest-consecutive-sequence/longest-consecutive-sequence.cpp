class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> se;
        for(auto &x : nums) se.insert(x);
        int ma = 0;
        for(auto &x : se) {
            int cnt = 1;
            int ele = x;
            if(se.find(ele-1) != se.end()) continue;
            while(se.find(ele+1) != se.end()) {
                cnt++;
                ele++;
            }
            ma = max(ma, cnt);
        }
        return ma;
    }
};
class Solution {
public:
    int totalFruit(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int first = 0,last = 0;
        int ma = 0;
        while(last < n) {
            while(first <= last && mp.size() > 2) {
                mp[nums[first]]--;
                if(mp[nums[first]] == 0) {
                    mp.erase(nums[first]);
                }
                first++;
            }
            mp[nums[last]]++;
            last++;
            if(mp.size() <= 2) {
                ma = max(ma, last-first);
            }
        }
        return ma;
    }
};
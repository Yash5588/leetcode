#include <cstdlib>
class Solution {
public:
    vector<int> nums;
    int size;
    Solution(int n, vector<int>& blacklist) {
        unordered_set<int> se(blacklist.begin(),blacklist.end());
        n = min(20000,n);
        for(int i = 0;i < n;i++) {
            if(!se.count(i)) nums.push_back(i); 
        }
        size = nums.size();
    }

    int pick() {
        int ind = rand() % size;
        return nums[ind];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
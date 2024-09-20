#include <cstdlib>
class Solution {
public:
    vector<int> nums;
    int size;
    Solution(int n, vector<int>& blacklist) {
        //nlogn time 
        //sorting and removing all the duplicates
        unordered_set<int> se(blacklist.begin(),blacklist.end());
        //get all the elements in range n which are not present
        //in nums
        n = min(100000,n);
        for(int i = 0;i < n;i++) {
            if(!se.count(i)) nums.push_back(i); 
        }
        size = nums.size();
    }

    int pick() {
        //pick a random index and send it from nums 
        //these are anyway not present in black box
        int ind = rand() % size;
        return nums[ind];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
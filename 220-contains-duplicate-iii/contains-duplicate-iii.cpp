class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();
        //window size is indexDiff
        multiset<int> se;
        int k = indexDiff + 1;
        for(int i = 0;i < min(k,n);i++) {
            auto iter = se.lower_bound(nums[i]);
            if(iter != se.end()) {
                if(abs(nums[i]-*iter) <= valueDiff) return true;
                if(abs(*iter-nums[i]) <= valueDiff) return true;
            }
            if(iter != se.begin()) {
                iter--;
                if(abs(nums[i]-*iter) <= valueDiff) return true;
                if(abs(*iter-nums[i]) <= valueDiff) return true;
            }
            se.insert(nums[i]);
        }
        for(int i = 0;i < n-k;i++) {
            se.erase(se.find(nums[i]));
            auto iter = se.lower_bound(nums[i+k]);
            if(iter != se.end()) {
                if(abs(nums[i+k]-*iter) <= valueDiff) return true;
                if(abs(*iter-nums[i+k]) <= valueDiff) return true;
            }
            if(iter != se.begin()) {
                iter--;
                if(abs(nums[i+k]-*iter) <= valueDiff) return true;
                if(abs(*iter-nums[i+k]) <= valueDiff) return true;
            }
            se.insert(nums[i+k]);
        }
        return false;
    }
};
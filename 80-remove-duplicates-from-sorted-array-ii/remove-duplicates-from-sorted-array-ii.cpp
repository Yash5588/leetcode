class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int first = 0,last = 0;
        while(last < n) {
            int count = 1;
            while(last+1 < n && nums[last] == nums[last+1]) {
                count++;
                last++;
            }
            int move = min(2,count);
            while(move--) {
                nums[first] = nums[last];
                first++;
            }
            last++;
        }
        return first;
    }
};
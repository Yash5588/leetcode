class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int  first = -1,last = -1;
        stack<int> sta1,sta2;
        //find previous greater element for lower boundary
        for(int i=0;i<n;i++) {
            //popping equal also because we need only greater element
            while(!sta1.empty() && sta1.top() <= nums[i]) {
                sta1.pop();
            }
            if(!sta1.empty()) {
                first = i;
            // we need to find the index of previous greater element
            }
            sta1.push(nums[i]);
        }

        for(int i=n-1;i>=0;i--) {
            while(!sta2.empty() && sta2.top() >= nums[i]) {
                sta2.pop();
            }
            if(!sta2.empty()) {
                last = i;
            }
            //we need to find the last index for next smaller element
            sta2.push(nums[i]);
        }
        if(last == -1) {
            return 0;
        }
        //this is the interval length for sorting largest length
        return first-last+1;
    }
};
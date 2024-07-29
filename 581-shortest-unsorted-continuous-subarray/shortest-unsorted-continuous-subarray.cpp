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
            // why i-1? because there is element which is greater than current element i so we need to consider i-1;
            }
            sta1.push(nums[i]);
        }
        //need to find upper boundary so to find that we iterate from last and find next smaller element
        for(int i=n-1;i>=0;i--) {
            while(!sta2.empty() && sta2.top() >= nums[i]) {
                sta2.pop();
            }
            if(!sta2.empty()) {
                last = i;
            }
            //why i+1? same as above reason we need to consider next element also
            sta2.push(nums[i]);
        }
        if(last == -1) {
            return 0;
        }
       return first-last+1;
    }
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Morre's voting algorithm
        int n = nums.size();
        int cnt = 0;
        int ele;
        for(int i = 0;i < n;i++) {
            if(cnt == 0) {
                ele = nums[i];
                cnt = 1;
            }
            else if(nums[i] == ele) {
                cnt++;
            }
            else cnt--;
        }
        //majority element check whether it exists
        int cnt1 = count(nums.begin(),nums.end(),ele);
        if(cnt1 > n/2) return ele;
        return -1;
    }
};
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp= nums;
        sort(nums.begin(),nums.end());
        int ind1 = -1,ind2 = -1;
        for(int i=0;i<n;i++) {
            if(temp[i] != nums[i]) {
                ind1 = i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--) {
            if(temp[i] != nums[i]) {
                ind2 = i;
                break;
            }
        }
        if(ind1 == -1) return 0;
        return ind2-ind1+1;
    }
};
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> diff;
        for(int i=0;i<n-1;i++) {
            for(int j=i+1;j<n;j++) {
                diff.push_back(abs(nums[i]-nums[j]));
            }
        }
        nth_element(diff.begin(),diff.begin()+(k-1),diff.end());
        return diff[k-1];
    }
};
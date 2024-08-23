class Solution {
public:
    //nlogn
    int getPairs(vector<int> &nums, int dist) {
        int i = 0,n = nums.size();
        int pairs = 0;
        for(int j=1;j<n;j++) {
            while(i < j && nums[j] - nums[i] > dist) {
                i++;
            }
            pairs += (j-i);
        }
        return pairs;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int left = 0;
        int right = nums[n-1] - nums[0];
        int result = 0;
        while(left <= right) {
            int midist = left + (right-left)/2;
            int pairs = getPairs(nums,midist);
            if(pairs < k)  left = midist+1;
            else {
                result = midist;
                right = midist-1;
            }
        }
        return result;
    }
};
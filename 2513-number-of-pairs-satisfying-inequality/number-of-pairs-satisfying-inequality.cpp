class Solution {
public:
    long long count = 0;
    void countSubs(vector<int> &nums, int low, int mid, int high, int diff) {
        int i = low,j = mid + 1;
        while(j <= high) {
            int cnt = upper_bound(nums.begin()+low,nums.begin()+mid+1,nums[j]+diff) - (nums.begin()+low);
            count += cnt;
            j++;
        }
        sort(nums.begin()+low,nums.begin()+high+1);
    }
    void mergeSort(vector<int> &nums, int low, int high, int diff) {
        if(low >= high) return;
        int mid = low + (high - low)/2;
        mergeSort(nums,low,mid,diff);
        mergeSort(nums,mid+1,high,diff);
        countSubs(nums,low,mid,high,diff);
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        for(int i = 0;i < n;i++) {
            nums1[i] -= nums2[i];
        }
        mergeSort(nums1,0,n-1,diff);
        return count;
    }
};
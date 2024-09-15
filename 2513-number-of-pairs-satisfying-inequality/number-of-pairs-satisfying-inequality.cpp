class Solution {
public:
    long long count = 0;
    //in merging algorithm
    void countSubs(vector<int> &nums, int low, int mid, int high, int diff) {
        //in merging we know that if we consider two subarrays
        //low -> mid and mid+1 -> high
        //both are sorted assume that and also i and j pairs are
        //completed in each subarray
        //i is fixed in low -> mid
        //j is fixed in mid+1->high
        int i = low,j = mid + 1;
        while(j <= high) {
            //now use binary search
            //fix j in 2nd subarray apply lower bound to satisfy inequality
            //nums[i] <= nums[j] + diff for this in first subarray
            int cnt = upper_bound(nums.begin()+low,nums.begin()+mid+1,nums[j]+diff) - (nums.begin()+low);
            count += cnt;
            j++;
        }
        //after completing we are merging both subarrays
        //so sort them before hand so that it can be helpful for upper levels
        sort(nums.begin()+low,nums.begin()+high+1);
    }
    void mergeSort(vector<int> &nums, int low, int high, int diff) {
        if(low >= high) return;
        int mid = low + (high - low)/2;
        mergeSort(nums,low,mid,diff);
        mergeSort(nums,mid+1,high,diff);
        //apply merging
        countSubs(nums,low,mid,high,diff);
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        //rearranging equation
        //nums1[i] - nums2[i] <= nums1[j] - nums2[j] + diff
        //c[i] <= c[j] + diff; c[i] = nums1[i] - nums2[i]
        for(int i = 0;i < n;i++) {
            nums1[i] -= nums2[i];
        }
        //apply merge sort
        mergeSort(nums1,0,n-1,diff);
        return count;
    }
};
class Solution {
public:
    int count = 0;
    void merge(vector<int> &nums, int low, int mid, int high) {
        int i = low,j = mid+1;
        while(i <= mid && j <= high) {
            if(nums[i] > (long long)2*nums[j]) {
                count += (high - j + 1);
                i++;
            }
            else {
                j++;
            }
        }
        vector<int> temp;
        i = low;
        j = mid+1;
        while(i <= mid && j <= high) {
            if(nums[i] > nums[j]) {
                temp.push_back(nums[i]);
                i++;
            }
            else {
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }
        while(j <= high) {
            temp.push_back(nums[j]);
            j++;
        }
        for(int i = low;i <= high;i++) {
            nums[i] = temp[i-low];
        }
    }
    void mergeSort(vector<int> &nums, int low, int high) {
        if(low < high) {
            int mid = low + (high - low)/2;
            mergeSort(nums, low, mid);
            mergeSort(nums, mid+1, high);
            merge(nums, low, mid, high);
        }
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums,0,n-1);
        return count;
    }
};
class Solution {
public:
    void merge(vector<pair<int,int>> &arr, int low, int mid, int high, vector<int> &count) {
        int i = low, j = mid+1;
        vector<pair<int,int>> temp;
        while(i <= mid && j <= high) {
            if(arr[i].first <= arr[j].first) {
                temp.push_back(arr[j]);
                j++;
            }
            else {
                //when we are fixing the left element position
                //in right subarray the remaining elements from j -> high are smaller than it
                //also are in right side so we add them
                count[arr[i].second] += (high - j + 1);
                temp.push_back(arr[i]);
                i++;
            }
        }
        while(i <= mid) {
            temp.push_back(arr[i]);
            i++;
        }
        while(j <= high) {
            temp.push_back(arr[j]);
            j++;
        }
        for(int i = low;i <= high;i++) {
            arr[i] = temp[i-low];
        }
    }
    void mergeSort(vector<pair<int,int>> &arr, int low, int high, vector<int> &count) {
        if(low >= high) return;
        int mid = low + (high - low)/2;
        mergeSort(arr,low,mid,count);
        mergeSort(arr,mid+1,high,count);
        merge(arr,low,mid,high,count);
    }
    vector<int> countSmaller(vector<int>& nums) {
        //basically this is counting inversion technique
        //of merge sort
        int n = nums.size();
        vector<int> count(n,0);
        vector<pair<int,int>> arr;
        for(int i = 0;i < n;i++) {
            arr.push_back({nums[i],i});
        }
        mergeSort(arr,0,n-1,count);
        return count;
    }
};
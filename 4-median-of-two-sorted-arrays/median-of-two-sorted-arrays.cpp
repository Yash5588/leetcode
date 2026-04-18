class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int cnt = 0;
        int m = nums1.size();
        int n = nums2.size();
        int mid = (m+n)/2;
        int flag = (m+n) & 1;
        int ele1 = 0,ele2 = 0;
        int i = 0,j = 0;
        while(i < m && j < n) {
            cnt++;
            if(nums1[i] <= nums2[j]) {
                if(cnt == mid) ele1 = nums1[i];
                if(cnt == mid+1) ele2 = nums1[i];
                i++;
            }
            else {
                if(cnt == mid) ele1 = nums2[j];
                if(cnt == mid+1) ele2 = nums2[j];
                j++;
            }
        }
        while(i < m) {
            cnt++;
            if(cnt == mid) ele1 = nums1[i];
            if(cnt == mid+1) ele2 = nums1[i];
            i++;
        }
        while(j < n) {
            cnt++;
            if(cnt == mid) ele1 = nums2[j];
            if(cnt == mid+1) ele2 = nums2[j];
            j++;
        }
        cout << ele1 << ' ' << ele2 << endl;
        if(flag) return ele2;
        return (ele1+ele2)/2.0;
    }
};
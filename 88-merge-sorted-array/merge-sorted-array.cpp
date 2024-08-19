class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //'i' point to last to last element in nums1, 'j' point
        //to last element in nums2 
        //curr to last index in nums1 where we can fill
        int i = m-1,j = n-1,curr = m+n-1;
        while(i >= 0 && j >= 0) {
            if(nums1[i] >= nums2[j]) {
                nums1[curr] = nums1[i];
                curr--;
                i--;
            }
            else {
                nums1[curr] = nums2[j];
                curr--;
                j--;
            }
        }
        //if elements are left in nums2 then assign them
        //if elements are left in nums1 then they are anyway in nums1 itself
        while(j >= 0) {
            nums1[curr] = nums2[j];
            curr--;
            j--; 
        }
    }
};
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findPeak(MountainArray &nums) {
        int n = nums.length();
        int low = 0,high = n - 1;
        int ind = -1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(mid == 0 || nums.get(mid) > nums.get(mid-1)) {
                low = mid + 1;
                ind = mid;
            }
            else if(mid == n-1 || nums.get(mid) > nums.get(mid+1)) {
                high = mid - 1;
            }
        }
        return ind;
    }
    int binarySearch1(MountainArray &nums, int low, int high, int target) {
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(nums.get(mid) == target) return mid;
            else if(nums.get(mid) < target) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
    int binarySearch2(MountainArray &nums, int low, int high, int target) {
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(nums.get(mid) == target) return mid;
            else if(nums.get(mid) > target) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &nums) {
        int n = nums.length();
        int ind = findPeak(nums);
        if(nums.get(ind) == target) return ind;
        int left = binarySearch1(nums,0,ind-1,target);
        if(left != -1) return left;
        int right = binarySearch2(nums,ind+1,n-1,target);
        return right;
    }
};
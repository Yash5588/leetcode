class Solution {
public:
    long long check(long long prod, vector<int> &nums1, vector<int> &nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        //fix element in nums1
        long long total = 0;
        for(auto &ele1 : nums1) {
            //for positive ele1 in nums1 as we go from left to right in nums2 
            //the prod value increases
            if (ele1 > 0) {
                long long threshold = prod / ele1;
                //here for -ve values 
                //like -7 / 2 ==> -3 but we need -4 as result 
                //becoz 2 * -3 ==> -6 > -7 we don't need it
                //so to avoid it we have to handle floor division for -ve values
                //becoz in python it gives -4 but in cpp it gives -3
                //it truncates towars 0
                if(prod < 0 && prod % ele1 != 0) threshold--;

                //now get all the count of elements which are less than or equal to (prod / ele1)
                total += upper_bound(nums2.begin(), nums2.end(), threshold) - nums2.begin();
            } 

            //for negative ele1 in nums1 as we go from left to right in nums2
            //the product value decreases
            else if(ele1 < 0){
                //now get the count of all the elements which are greater than or equal to (prod / ele1)
                //don't  forget to take ceil becoz 
                //ex prod = 5 and ele1 = -2 and nums2 = [1,2,3,4,5]
                //the products are [-2,-4,-6,-8,-10]
                //the elements in nums2 which satisfy are 5
                //now prod / ele1 = 5 / -2 => -2.5(if float)
                //now lower bound is -4 which is not correct becoz -2 > -2.5
                //still we are including that so if we take ceil then -2.5 becomes -2
                //then lower bound gives -2 as result 
                //size - ind ==> 5 - 0 ==> 5 you can verify above
                total += (nums2.size() - (lower_bound(nums2.begin(), nums2.end(), ceil(prod / (double)ele1)) - nums2.begin()));
            }
            else {
                //ele1 == 0
                //then check the prod if it is positive then ele1 * ele2 ==> 0 and prod > 0 then all the elements satisfy even if we multiply we get result as 0 for all the elements
                if(prod >= 0) {
                    total += nums2.size();
                }
            }
        }
        return total;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        //now for all the possible products check the minimum product value such that which 
        //has number of products <= k
        long long res = -1;
        long long low = -1e10 - 1, high = 1e10 + 1;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (check(mid, nums1, nums2) >= k) {
                res = mid;    
                high = mid - 1;  
            } else {
                low = mid + 1; 
            }
        }
        return res;
    }
};
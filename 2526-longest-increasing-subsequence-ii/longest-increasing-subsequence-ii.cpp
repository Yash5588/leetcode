class SegmentTree{
    vector<int> segTree;
    public:
        SegmentTree(int n) {
            segTree.resize(4*n,0);
        }

        void update(int idx, int val, int i, int left, int right) {
            if(left == right) {
                segTree[i] = val;
                return;
            }
            int mid = left + (right - left)/2;
            if(idx <= mid) {
                update(idx, val, 2*i+1, left, mid);
            }
            else {
                update(idx, val, 2*i+2, mid+1, right);
            }
            segTree[i] = max(segTree[2*i+1], segTree[2*i+2]);
        }

        int query(int start, int end, int i, int left, int right) {
            if(end < left || start > right) return 0;
            if(start <= left && right <= end) return segTree[i];
            int mid = left + (right - left)/2;
            return max(query(start, end, 2*i+1, left, mid), query(start, end, 2*i+2, mid+1, right));
        }
};
class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size();
        //use regular lis tabulation of O(n^2)
        //but we use segment tree for getting max subsequence length for prev index
        vector<int> dp(n,1);
        //store elements as indices 
        //and for values we store the max subsequence starting from that element which is maximum
        int size = *max_element(nums.begin(),nums.end())+1;
        vector<int> ele_index(size,0);
        for(int i = 0;i < n;i++) {
            ele_index[nums[i]] = 1;
        }
        SegmentTree seg(size);
        int res = INT_MIN;
        for(int i = n-1;i >= 0;i--) {
            int start = nums[i] + 1;
            int end = nums[i] + k;
            int idx = nums[i];
            int next_max = seg.query(start, end, 0, 0, size-1);
            dp[i] = next_max + 1;

            //store max possible lis from all indices
            res = max(res, dp[i]);

            //previous max subsequence starting from this element
            int p_max = seg.query(idx, idx, 0, 0, size-1);
            
            //currentlty formed subsequence length
            int c_max = dp[i];
            int val = max(p_max, c_max);
            seg.update(idx, val, 0, 0, size-1);
        }
        return res;
    }
};
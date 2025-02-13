int mod = 1e9 + 7;
class SegmentTree{
    int size;
    vector<long long> segTree;
    public:
        SegmentTree(int n) {
            size = n;
            segTree.resize(4*n, 0);
        }

        void buildTree(int i, int left, int right, vector<int> &nums) {
            if(left == right) {
                segTree[i] = nums[left];
                return;
            }

            int mid = left + (right - left)/2;
            buildTree(2*i+1, left, mid, nums);
            buildTree(2*i+2, mid+1, right, nums);
            segTree[i] = segTree[2*i+1] + segTree[2*i+2];
        }

        void pointUpdate(int idx, int val, int i, int left, int right) {
            if(left == right) {
                segTree[i] += val;
                return;
            }

            int mid = left + (right - left)/2;
            if(idx <= mid) {
                pointUpdate(idx, val, 2*i+1, left, mid);
            }
            else {
                pointUpdate(idx, val, 2*i+2, mid+1, right);
            }

            segTree[i] = segTree[2*i+1] + segTree[2*i+2];
        }

        long long rangeSumQuery(int start, int end, int i, int left, int right) {
            if(end < left || right < start || left > right) return 0;
            if(start <= left && right <= end) return segTree[i];
            int mid = left + (right - left)/2;
            return rangeSumQuery(start, end, 2*i+1, left, mid) + rangeSumQuery(start, end, 2*i+2, mid+1, right);
        }

        long long query(int start, int end) {
            return rangeSumQuery(start, end, 0, 0, size-1);
        }

        void update(int idx, int val) {
            pointUpdate(idx, val, 0, 0, size-1);
        }

};
class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        int n = instructions.size();
        int max_val = *max_element(instructions.begin(), instructions.end());
        long long res = 0;
        int size = max_val+1;
        SegmentTree seg(size);
        for(auto &x : instructions) {
            long long left_sum = seg.query(0, x-1);
            long long right_sum = seg.query(x+1, size-1);
            res += min(left_sum, right_sum);
            seg.update(x, 1);
        }
        return res % mod;
    }
};
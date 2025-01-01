class SegmentTree{
    vector<int> segTree;
    public:
        SegmentTree(int n) {
            segTree.resize(4*n,0);
        }

        void buildTree(int i, int left, int right, vector<int> &nums) {
            if(left == right) {
                segTree[i] = nums[left];
                return;
            }

            int mid = (left + right)/2;
            buildTree(2*i+1, left, mid, nums);
            buildTree(2*i+2, mid+1, right, nums);
            segTree[i] = segTree[2*i+1] + segTree[2*i+2];
        }

        void update(int idx, int val, int i, int left, int right) {
            if(left == right) {
                segTree[i] = val;
                return;
            }

            int mid = (left + right)/2;
            if(idx <= mid) {
                update(idx, val, 2*i+1, left, mid);
            }
            else {
                update(idx, val, 2*i+2, mid+1, right);
            }
            segTree[i] = segTree[2*i+1] + segTree[2*i+2];
        }

        int rangeSumQuery(int start, int end, int i, int left, int right) {
            if(end < left || start > right) return 0;
            if(start <= left && right <= end) return segTree[i];
            int mid = (left + right)/2;
            return rangeSumQuery(start, end, 2*i+1, left, mid) + rangeSumQuery(start, end, 2*i+2, mid+1, right);
        }
};
class NumArray {
public:
    SegmentTree seg;
    int N;
    NumArray(vector<int>& nums)  : seg(nums.size()){
        int n = nums.size();
        N = n;
        seg.buildTree(0, 0, n-1, nums);
    }
    
    void update(int index, int val) {
        seg.update(index, val, 0, 0, N-1);
    }
    
    int sumRange(int left, int right) {
        return seg.rangeSumQuery(left, right, 0, 0, N-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
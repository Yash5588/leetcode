class SegmentTree{
    vector<int> segTree;
    public:
        SegmentTree(int n) {
            //it's a full binary tree so make size this much
            segTree.resize(4*n,0);
        }

        void buildTree(int i, int left, int right, vector<int> &nums) {
            if(left == right) { //left node case 
                segTree[i] = nums[left];
                return;
            }

            //left half  and right half of range sum 
            int mid = (left + right)/2;
            //left half is present in left child 2*i+1
            buildTree(2*i+1, left, mid, nums);
            //right half is present in right child 2*i+2;
            buildTree(2*i+2, mid+1, right, nums);
            //left child and right child sum add to current index
            segTree[i] = segTree[2*i+1] + segTree[2*i+2];
        }

        void update(int idx, int val, int i, int left, int right) {
            //to update find the index first
            if(left == right) { //index found then update segTree
                segTree[i] = val;
                return;
            }

            int mid = (left + right)/2;
            if(idx <= mid) {
                //if present in left side move to left side
                update(idx, val, 2*i+1, left, mid);
            }
            else {
                //if present in right side move to right side
                update(idx, val, 2*i+2, mid+1, right);
            }
            //update the corresponding path while backtracking
            segTree[i] = segTree[2*i+1] + segTree[2*i+2];
        }

        int rangeSumQuery(int start, int end, int i, int left, int right) {
            //if target range is out of present range then we can't find sum here
            if(end < left || start > right) return 0;
            //if present range is inside target range then return entire sum 
            if(start <= left && right <= end) return segTree[i];
            //if there is some overlapping find in both sides
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
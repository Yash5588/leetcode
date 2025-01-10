class SegmentTree{
    private:
        vector<int> segTree,lazy;
        int size;
    public:
        SegmentTree(int n) {
            segTree.resize(4*n);
            lazy.resize(4*n,0);
            size = n;
        }

        void buildTree(int i, int left, int right, vector<int> &nums) {
            if(left == right) {
                segTree[i] = nums[left];
                return;
            }

            int mid = left + (right - left)/2;
            buildTree(2*i+1, left, mid, nums);
            buildTree(2*i+2, mid+1, right, nums);
            segTree[i] = max(segTree[2*i+1], segTree[2*i+2]);
        }

        void rangeUpdate(int start, int end, int i, int left, int right, int val) {
            if(lazy[i] != 0) {
                segTree[i] += lazy[i];
                if(left != right) {
                    lazy[2*i+1] += lazy[i];
                    lazy[2*i+2] += lazy[i];
                }
                lazy[i] = 0;
            }

            if(right < start || left > end) return;

            if(start <= left && right <= end) {
                segTree[i] += val;
                if(left != right) {
                    lazy[2*i+1] += val;
                    lazy[2*i+2] += val;
                }
                return;
            }

            int mid = left + (right - left)/2;
            rangeUpdate(start, end, 2*i+1, left, mid, val);
            rangeUpdate(start, end, 2*i+2, mid+1, right, val);

            segTree[i] = max(segTree[2*i+1], segTree[2*i+2]);
        }

        int rangeMaxQuery(int start, int end, int i, int left, int right) {
            if(lazy[i] != 0) {
                segTree[i] += lazy[i];
                if(left != right) {
                    lazy[2*i+1] += lazy[i];
                    lazy[2*i+2] += lazy[i];
                }
                lazy[i] = 0;
            }

            if(right < start || left > end) return INT_MIN;
            if(start <= left && right <= end) return segTree[i];

            int mid = left + (right - left)/2;
            int leftMax = rangeMaxQuery(start, end, 2*i+1, left, mid);
            int rightMax = rangeMaxQuery(start, end, 2*i+2, mid+1, right);
            return max(leftMax, rightMax);
        }

        void update(int start, int end, int val) {
            rangeUpdate(start, end, 0, 0, size-1, val);
        }

        int query(int start, int end) {
            return rangeMaxQuery(start, end, 0, 0, size-1);
        }

};
class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int N = 0;
        //max size of x coordinate for size of segment tree
        for(auto &q : queries) {
            N = max(N, q[1]);
        }

        set<int> se;
        //to avoid extra if conditions for boundary
        se.insert(0);
        se.insert(N+1);

        SegmentTree seg(N+2);
        //initialize the segTree  with same size
        for(int i = 0;i < N+2;i++) {
            seg.update(i,i,i);
        }

        vector<bool> res;
        for(auto &q : queries) {
            int x = q[1];
            if(q[0] == 2) {
                int sz = q[2];
                int max_val = seg.query(0, x);
                if(sz <= max_val) res.push_back(true);
                else res.push_back(false);
            }
            else {
                int end = *se.upper_bound(x);
                int dec = -1 * seg.query(x,x);
                seg.update(x+1, end, dec);
                se.insert(x);
            }
        }
        return res;

    }
};
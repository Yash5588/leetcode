class SegmentTree{
    vector<int> segTree;
    public:
        SegmentTree(int n) {
            segTree.resize(4*n,INT_MIN);
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

        bool query(int i, int left, int right, int val) {
        if (left == right) {
            if (segTree[i] >= val) {
                segTree[i] = -1; // Mark the basket as used
                return true;
            }
            return false;
        }

        if(segTree[i] < val) return false;
        
        int mid = left + (right - left) / 2;
        bool isLeft = query(2 * i + 1, left, mid, val);
        if (isLeft) {
            segTree[i] = max(segTree[2 * i + 1], segTree[2 * i + 2]);
            return true;
        }
        bool isRight = query(2 * i + 2, mid + 1, right, val);
        if (isRight) {
            segTree[i] = max(segTree[2 * i + 1], segTree[2 * i + 2]);
            return true;
        }
        return false;
    }
};
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int leftOut = 0;
        SegmentTree seg(n);
        seg.buildTree(0,0,n-1,baskets);
        for(int i = 0;i < n;i++) {
            if(!seg.query(0,0,n-1,fruits[i])) leftOut++;
        }
        return leftOut;
    }
};
class SegmentTree{
    int size;
    vector<int> segTree;
    public:
        SegmentTree(int n) {
            segTree.resize(4*n,0);
            size = n;
        }

        void buildTree(vector<int> &nums, int i, int left, int right) {
            if(left == right) {
                segTree[i] = nums[left];
                return;
            }

            int mid = left + (right - left)/2;
            buildTree(nums, 2*i+1, left, mid);
            buildTree(nums, 2*i+2, mid+1, right);
            segTree[i] = segTree[2*i+1] + segTree[2*i+2];
        }

        void update(int ind, int val, int i, int left, int right) {
            if(left == right) {
                segTree[i] = val;
                return;
            }

            int mid = left + (right - left)/2;
            if(ind <= mid) {
                update(ind, val, 2*i+1, left, mid);
            }
            else {
                update(ind, val, 2*i+2, mid+1, right);
            }
            segTree[i] = segTree[2*i+1] + segTree[2*i+2];
        }

        int rangeSumQuery(int start, int end, int i, int left, int right) {
            if(start <= left && right <= end) return segTree[i];
            if(right < start || left > end) return 0;
            int mid = left + (right - left)/2;
            return rangeSumQuery(start, end, 2*i+1, left, mid) + rangeSumQuery(start, end, 2*i+2, mid+1, right);
        }
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        SegmentTree seg(n);
        vector<pair<int,int>> pairs;
        for(int i = 0;i < n;i++) {
            pairs.push_back({nums[i],i});
        }
        sort(pairs.begin(),pairs.end());
        vector<int> bit(n,0);
        vector<int> res(n);
        // seg.buildTree(bit, 0, 0, n-1); //building segment tree for bit array
        for(auto &x : pairs) {
            int ind = x.second;
            int sum = seg.rangeSumQuery(ind, n-1, 0, 0, n-1);
            res[ind] = sum;
            bit[ind] = 1;
            seg.update(ind, 1, 0, 0, n-1);
        }
        return res;
    }
};
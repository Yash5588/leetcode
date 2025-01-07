class SegmentTree {
    vector<int> segTree, lazy;
public:
    SegmentTree(int n) {
        segTree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }

    void propagate(int i, int left, int right) {
        if (lazy[i] != 0) {
            segTree[i] = max(segTree[i], lazy[i]);
            if (left != right) { // Propagate lazily
                lazy[2 * i + 1] = max(lazy[2 * i + 1], lazy[i]);
                lazy[2 * i + 2] = max(lazy[2 * i + 2], lazy[i]);
            }
            lazy[i] = 0; // Clear lazy value for this node
        }
    }

    int rangeMaxQuery(int start, int end, int i, int left, int right) {
        propagate(i, left, right); // Apply pending updates
        if (start > right || end < left) return INT_MIN; // No overlap
        if (start <= left && right <= end) return segTree[i]; // Full overlap
        int mid = left + (right - left) / 2;
        return max(rangeMaxQuery(start, end, 2 * i + 1, left, mid),
                   rangeMaxQuery(start, end, 2 * i + 2, mid + 1, right));
    }

    void updateRange(int start, int end, int i, int left, int right, int val) {
        propagate(i, left, right); // Apply pending updates
        if (start > right || end < left) return; // No overlap
        if (start <= left && right <= end) { // Full overlap
            lazy[i] = val;
            propagate(i, left, right);
            return;
        }
        int mid = left + (right - left) / 2;
        updateRange(start, end, 2 * i + 1, left, mid, val);
        updateRange(start, end, 2 * i + 2, mid + 1, right, val);
        segTree[i] = max(segTree[2 * i + 1], segTree[2 * i + 2]); // Recalculate
    }
};

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        set<int> se;
        for(auto &pos : positions) {
            se.insert(pos[0]);
            //-1 becoz brushing of other square on current square doesn't mean falling on it
            //to avoid we remove last coordinate from square
            se.insert(pos[0] + pos[1] - 1);
        }

        //assign indices for sorted coordinates.
        int ind = 0;
        unordered_map<int,int> coord_ind;
        for(auto &x : se) {
            coord_ind[x] = ind++;
        }

        //now perform range query in segment tree along with lazy propagation
        vector<int> res;
        int max_height = INT_MIN;
        int n = se.size();
        SegmentTree seg(n);
        for(auto &pos : positions) {
            int start = coord_ind[pos[0]];
            int end = coord_ind[pos[0] + pos[1] - 1];
            int currHeight = seg.rangeMaxQuery(start, end, 0, 0, n-1) + pos[1];
            max_height = max(max_height, currHeight);
            seg.updateRange(start, end, 0, 0, n-1, currHeight);
            res.push_back(max_height);
        }
        return res;
    }
};
class SegmentTree{
    private:
        vector<int> tree,lazy;
        int size;
    public:
        SegmentTree(int n) {
            tree.resize(4*n);
            lazy.resize(4*n,0);
            size = n;
        }

        // void buildTree(int i, int left, int right, vector<int> &nums) {
        //     if(left == right) {
        //         segTree[i] = nums[left];
        //         return;
        //     }

        //     int mid = left + (right - left)/2;
        //     buildTree(2*i+1, left, mid, nums);
        //     buildTree(2*i+2, mid+1, right, nums);
        //     segTree[i] = max(segTree[2*i+1], segTree[2*i+2]);
        // }

       void updateRangeUtil(int si, int ss, int se, int us,
                     int ue, int diff)
        {
            // If lazy value is non-zero for current node of segment
            // tree, then there are some pending updates. So we need
            // to make sure that the pending updates are done before
            // making new updates. Because this value may be used by
            // parent after recursive calls (See last line of this
            // function)
            if (lazy[si] != 0) {
                // Make pending updates using value stored in lazy
                // nodes
                tree[si] += lazy[si];
        
                // Checking if it is not leaf node because if
                // it is leaf node then we cannot go further
                if (ss != se) {
                    // We can postpone updating children we don't
                    // need their new values now.
                    // Since we are not yet updating children of si,
                    // we need to set lazy flags for the children
                    lazy[si * 2 + 1] += lazy[si];
                    lazy[si * 2 + 2] += lazy[si];
                }
        
                // Set the lazy value for current node as 0 as it
                // has been updated
                lazy[si] = 0;
            }
        
            // Out of range
            if (ss > se || ss > ue || se < us)
                return;
        
            // Current segment is fully in range
            if (ss >= us && se <= ue) {
                // Add the difference to current node
                tree[si] += diff;
        
                // Same logic for checking leaf node or not
                if (ss != se) {
                    // This is where we store values in lazy nodes,
                    // rather than updating the segment tree itself
                    // Since we don't need these updated values now
                    // we postpone updates by storing values in lazy[]
                    lazy[si * 2 + 1] += diff;
                    lazy[si * 2 + 2] += diff;
                }
                return;
            }
        
            // If not completely in range, but overlaps
            // recur for children
            int mid = (ss + se) / 2;
            updateRangeUtil(si * 2 + 1, ss, mid, us, ue, diff);
            updateRangeUtil(si * 2 + 2, mid + 1, se, us, ue, diff);
        
            // And use the result of children calls
            // to update this node
            tree[si] = max(tree[si * 2 + 1], tree[si * 2 + 2]);
        }
        
        // Function to update a range of values in segment
        // tree
        // us and eu -> starting and ending indexes of update query
        // ue -> ending index of update query
        // diff -> which we need to add in the range us to ue
        void updateRange(int n, int us, int ue, int diff)
        {
            updateRangeUtil(0, 0, n - 1, us, ue, diff);
        }
        
        // A recursive function to get the max of values in given
        // a range of the array. The following are the parameters
        // for this function
        // si --> Index of the current node in the segment tree
        // Initially, 0 is passed as root is always at index 0
        // ss & se --> Starting and ending indexes of the
        // segment represented by current node
        // i.e., tree[si]
        // qs & qe --> Starting and ending indexes of query
        // range
        int getMaxUtil(int ss, int se, int qs, int qe, int si)
        {
        
            // If lazy flag is set for current node of segment tree
            // then there are some pending updates. So we need to
            // make sure that the pending updates are done before
            // processing the sub sum query
            if (lazy[si] != 0) {
        
                // Make pending updates to this node. Note that this
                // node represents sum of elements in arr[ss..se] and
                // all these elements must be increased by lazy[si]
                tree[si] += lazy[si];
        
                // Checking if it is not leaf node because if
                // it is leaf node then we cannot go further
                if (ss != se) {
                    // Since we are not yet updating children os si,
                    // we need to set lazy values for the children
                    lazy[si * 2 + 1] += lazy[si];
                    lazy[si * 2 + 2] += lazy[si];
                }
        
                // Unset the lazy value for current node as it has
                // been updated
                lazy[si] = 0;
            }
        
            // Out of range
            if (ss > se || ss > qe || se < qs)
                return 0;
        
            // At this point, we are sure that pending lazy updates
            // are done for current node. So we can return value
            // (same as it was for a query in our previous post)
        
            // If this segment lies in range
            if (ss >= qs && se <= qe)
                return tree[si];
        
            // If a part of this segment overlaps with the given
            // range
            int mid = (ss + se) / 2;
            return max(getMaxUtil(ss, mid, qs, qe, 2 * si + 1),
                    getMaxUtil(mid + 1, se, qs, qe, 2 * si + 2));
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
            seg.updateRange(N+2, i, i, i);
        }

        vector<bool> res;
        for(auto &q : queries) {
            int x = q[1];
            if(q[0] == 2) {
                int sz = q[2];
                int max_val = seg.getMaxUtil(0, N+1, 0, x, 0);
                if(sz <= max_val) res.push_back(true);
                else res.push_back(false);
            }
            else {
                int end = *se.upper_bound(x);
                int dec = -1 * seg.getMaxUtil(0, N+1, x, x, 0);
                // cout << x << endl;
                seg.updateRange(N+2, x+1, end, dec);
                se.insert(x);
            }
        }
        return res;

    }
};
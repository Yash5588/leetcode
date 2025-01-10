class SegmentTree{
    private:
        vector<int> segTree;
        int size;
    public:
        SegmentTree(int n) {
            segTree.resize(4*n);
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
            segTree[i] = segTree[2*i+1] + segTree[2*i+2];
        }

        void update(int i, int left, int right, int ind, int val) {
            if(left == right) {
                segTree[i] = val;
                return;
            }

            int mid = left + (right - left)/2;
            if(ind <= mid) {
                update(2*i+1, left, mid, ind, val);
            }
            else {
                update(2*i+2, mid+1, right, ind, val);
            }
            segTree[i] = segTree[2*i+1] + segTree[2*i+2];
        }

        int query(int start, int end, int i, int left, int right) {
            if(end < left || right < start) return 0;
            if(start <= left && right <= end) return segTree[i];
            int mid = left + (right - left)/2;
            return query(start, end, 2*i+1, left, mid) + query(start, end, 2*i+2, mid+1, right);
        }
};
class Solution {
public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        //mark the peak elements in binary tree
        int n = nums.size();
        vector<int> peaks(n,0);
        for(int i = 1;i < n-1;i++) {
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) {
                peaks[i] = 1;
            }
        }
        SegmentTree seg(n);
        vector<int> res;
        seg.buildTree(0, 0, n-1, peaks);
        for(auto &q : queries) {
            if(q[0] == 1) {
                // for(int i = 0;i < n;i++) cout << peaks[i] << endl;
                // cout << endl;
                int val = seg.query(q[1], q[2] ,0 ,0 ,n-1);
                val -= peaks[q[1]];
                if(q[1] != q[2]) val -= peaks[q[2]];
                res.push_back(val);
            } 
            else {
                nums[q[1]] = q[2];
                int ind  = q[1];
                if(ind-1 >= 0 && ind+1 < n) {
                    if(nums[ind-1] < nums[ind] && nums[ind+1] < nums[ind]) {
                        peaks[ind] = 1;
                        seg.update(0, 0, n-1, ind, 1);
                        peaks[ind-1] = 0;
                        seg.update(0, 0, n-1, ind-1, 0);
                        peaks[ind+1] = 0;
                        seg.update(0, 0, n-1, ind+1, 0);
                    }
                    else {
                        peaks[ind] = 0;
                        seg.update(0, 0, n-1, ind, 0);
                    }
                }
                //check ind -1 and ind +1 as peaks
                if(peaks[ind] != 1) {
                    int left = ind-1;
                    if(left-1 >= 0 && left+1 < n) {
                        if(nums[left-1] < nums[left] && nums[left+1] < nums[left]) {
                            peaks[left] = 1;
                            seg.update(0, 0, n-1, left, 1);
                        }
                        else {
                            peaks[left] = 0;
                            seg.update(0, 0, n-1, left, 0);
                        }
                    }
                    int right = ind+1;
                    if(right-1 >= 0 && right+1 < n) {
                        if(nums[right-1] < nums[right] && nums[right+1] < nums[right]) {
                            peaks[right] = 1;
                            seg.update(0, 0, n-1, right, 1);
                        }
                        else {
                            peaks[right] = 0;
                            seg.update(0, 0, n-1, right, 0);
                        }
                    }
                }
                // cout << peaks[q[1]] << endl;
                // for(int i = 0;i < n;i++) cout << peaks[i] << ' ';
                // cout << endl;
            }
        }
        return res;
    }
};
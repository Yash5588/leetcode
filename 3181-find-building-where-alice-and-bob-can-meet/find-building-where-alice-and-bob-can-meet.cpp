//RMIQ
class SegmentTree{
    vector<int> segTree;
    int size;
    public:
        SegmentTree(int n) {
            segTree.resize(4*n);
            size = n;
        }

        void buildTree(vector<int> &nums, int i, int left, int right) {
            if(left == right) { //left node
                segTree[i] = left; //index
                return;
            }

            int mid = left + (right - left)/2;
            buildTree(nums, 2*i+1, left, mid);
            buildTree(nums, 2*i+2, mid+1, right);
            //update with indices
            int leftInd = segTree[2*i+1];
            int rightInd = segTree[2*i+2];
            if(nums[leftInd] >= nums[rightInd]) {
                segTree[i] = leftInd;
            }
            else segTree[i] = rightInd;
        }

        int rangeMaxIndexQuery(vector<int> &nums, int start, int end, int i, int left, int right) {
            //out of bound
            if(right < start || left > end) return -1; //invalid index
            //completely present
            if(start <= left && end >= right) return segTree[i]; //return index
            
            int mid = left + (right - left)/2;
            int leftInd = rangeMaxIndexQuery(nums, start, end, 2*i+1, left, mid);
            int rightInd = rangeMaxIndexQuery(nums, start, end, 2*i+2, mid+1, right);
            //check invalid indices
            if(leftInd == -1) return rightInd;
            if(rightInd == -1) return leftInd;
            if(nums[leftInd] >= nums[rightInd]) {
                return leftInd;
            }
            return rightInd;
        }
};
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        vector<int> res;
        SegmentTree seg(n);
        seg.buildTree(heights, 0, 0, n-1);
        for(auto &q : queries) {
            if(q[0] == q[1]) {
                res.push_back(q[0]);
                continue;
            }
            int leftInd = min(q[0], q[1]);
            int rightInd = max(q[0], q[1]);
            if(heights[leftInd] < heights[rightInd]) res.push_back(rightInd);
            else {
                int low = rightInd+1;
                int high = n-1;
                int ans = -1;

                while(low <= high) {
                    int mid = low + (high - low)/2;
                    int idx = seg.rangeMaxIndexQuery(heights, low, mid, 0, 0, n-1);
                    if(idx != -1 && heights[idx] > max(heights[leftInd],heights[rightInd])) {
                        ans = idx;
                        high = mid - 1;
                    }
                    else low = mid + 1;
                }
                res.push_back(ans);
            }
        }
        return res;
    }
};
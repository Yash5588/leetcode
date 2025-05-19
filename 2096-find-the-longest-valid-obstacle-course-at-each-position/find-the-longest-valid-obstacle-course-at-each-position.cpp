class SegmentTree{
    vector<int> segTree;
    public:
        SegmentTree(int n) {
            segTree.resize(4*n, 0);
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
            segTree[i] = max(segTree[2*i+1], segTree[2*i+2]);
        }

        int rangeMaxQuery(int start, int end, int i, int left, int right) {
            if(right < start || left > end) return 0;
            if(start <= left && right <= end) return segTree[i];
            int mid = (left + right)/2;
            return max(rangeMaxQuery(start,end, 2*i+1, left, mid), rangeMaxQuery(start, end, 2*i+2, mid+1, right));
        }
};
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        unordered_map<int,int> indices;
        vector<int> temp;
        temp = obstacles;
        sort(temp.begin(),temp.end());
        temp.erase(unique(temp.begin(),temp.end()), temp.end());
        int size = temp.size();
        for(int i = 0;i < size;i++) {
            indices[temp[i]] = i;
        }

        SegmentTree seg(size);
        vector<int> res;
        for(auto &x : obstacles) {
            int idx = indices[x];
            int max_len = seg.rangeMaxQuery(0,idx,0,0,size-1) + 1;
            res.push_back(max_len);
            seg.update(idx, max_len, 0, 0, size-1);
        }
        return res;
    }
};
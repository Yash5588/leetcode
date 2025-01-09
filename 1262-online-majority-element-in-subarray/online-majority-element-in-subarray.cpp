//first -> denotes element
//second -> denotes freq(not exactly freq though)
class SegmentTree{
    private:
        vector<pair<int,int>> segTree;
        int size;
    public:
        void set(int n) {
            segTree.resize(4 * n);
            size = n;
        }

        pair<int,int> merge(pair<int,int> &a, pair<int,int> &b) {
            pair<int,int> res;
            if(a.first == b.first) {
                //both elements are equal add both freq
                res = {a.first, a.second + b.second};
            }
            //moore's voting of majority
            //greater freq element is considered with subtracting both freq
            //just like in moore's algo
            else if(a.second > b.second) {
                res = {a.first, a.second - b.second};
            } 
            else {
                res = {b.first, b.second - a.second};
            }
            return res;
        }

        void buildTree(int i, int left, int right, vector<int> &nums) {
            if(left == right) {
                segTree[i] = {nums[left], 1};
                return;
            }

            int mid = left + (right - left)/2;
            buildTree(2*i+1, left, mid, nums);
            buildTree(2*i+2, mid+1, right, nums);

            segTree[i] = merge(segTree[2*i+1], segTree[2*i+2]);
        }

        pair<int,int> majorQuery(int start, int end, int i, int left, int right) {
            if(right < start || left > end) return {0,0};
            if(start <= left && right <= end) return segTree[i];
            int mid = left + (right - left)/2;
            pair<int,int> l = majorQuery(start, end, 2*i+1, left, mid);
            pair<int,int> r = majorQuery(start, end, 2*i+2, mid+1, right);
            return merge(l,r);
        }

        int Query(int start, int end) {
            return majorQuery(start, end, 0, 0, size-1).first;
        }

        void build(vector<int> &nums) {
            buildTree(0, 0, size-1, nums);
        }


};
class MajorityChecker {
public:
    unordered_map<int,vector<int>> indices;
    SegmentTree seg;
    MajorityChecker(vector<int>& arr) {
        int n = arr.size();
        //store indices
        for(int i = 0;i < n;i++) {
            indices[arr[i]].push_back(i);
        }
        seg.set(n);
        seg.build(arr);
    }
    
    int query(int left, int right, int threshold) {
        //this is majority but we need to compare with threshold
        int ele = seg.Query(left, right);
        int l = lower_bound(indices[ele].begin(), indices[ele].end(), left) - indices[ele].begin(); 
        int r = upper_bound(indices[ele].begin(), indices[ele].end(), right) - indices[ele].begin(); 
        if(r - l >= threshold) return ele;
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
class SegmentTree{
    vector<unordered_map<int,int>> segTree;
    public:
        SegmentTree(int n) {
            segTree.resize(4*n);
        }

        void buildTree(int i, int left,int right, vector<int> &nums) {

            unordered_map<int,int> mp = segTree[i];

            if(left == right) {
                int val = nums[left];
                segTree[i][val] = 1;
                return; 
            }
            int mid = left + (right - left)/2;
            buildTree(2*i+1, left, mid, nums);
            buildTree(2*i+2, mid+1, right, nums);

            for(auto &[key,val] : segTree[2*i+1]) {
                mp[key] += val;
            }

            for(auto &[key,val] : segTree[2*i+2]) {
                mp[key] += val;
            }

            segTree[i] = mp;

        }

        int query(int start, int end, int i, int left, int right, int val) {
            if(end < left || start > right) return 0;
            if(start <= left && right <= end) return segTree[i][val];
            int mid = (left + right) / 2;
            return query(start, end, 2*i+1, left, mid, val) + query(start, end, 2*i+2, mid+1, right, val);
        }
};
class RangeFreqQuery {
public:
    int n;
    SegmentTree seg;
    RangeFreqQuery(vector<int>& arr) : n(arr.size()), seg(n){
        // n = arr.size();
        seg.buildTree(0,0,n-1,arr);
    }
    
    int query(int left, int right, int value) {
        return seg.query(left, right, 0, 0, n-1, value);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
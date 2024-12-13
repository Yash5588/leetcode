class NumArray {
public:
    vector<int> bit;
    vector<int> arr;
    int size;
    int query(int id) {
        int ans = 0;
        while(id > 0) {
            ans += bit[id];
            id -= (id & -id); //removing last set bit in each iteration
        }
        return ans;
    }

    void updateQuery(int id, int val) {
        while(id <= size) {
            bit[id] += val;
            id += (id & -id);
        }
    }

    NumArray(vector<int>& nums) {
        int n = nums.size();
        size = n;
        arr = nums;
        bit.resize(n+1,0);
        for(int i = 0;i < n;i++) {
            updateQuery(i+1,nums[i]); //update 1 based indexing
        }
    }
    
    void update(int index, int val) {
        updateQuery(index+1,-arr[index]); // remove element
        updateQuery(index+1,val); // add new element
        arr[index] = val; //update our array as well
    }
    
    int sumRange(int left, int right) {
        //sum = query(r) - query(l-1) l,r => 1 - based indexing
        int leftSum = query(left);
        int rightSum = query(right+1);
        return rightSum - leftSum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
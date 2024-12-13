class Solution {
public:
    vector<int> bit;
    int size;

    int query(int id) {
        int sum = 0;
        while(id > 0) {
            sum += bit[id];
            id -= (id & -id);
        }
        return sum;
    }

    void update(int id, int val) {
        while(id <= size) {
            bit[id] += val;
            id += (id & -id);
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        size = n;
        bit.resize(n+1);
        vector<pair<int,int>> ind_pairs;
        for(int i = 0;i < n;i++) {
            ind_pairs.push_back({nums[i],i});
        }
        sort(ind_pairs.begin(),ind_pairs.end());
        //populate bit array
        for(int i = 0;i < n;i++) {
            update(i+1, 0);
        }
        vector<int> res(n);
        for(auto &x : ind_pairs) {
            int idx = x.second;
            //1 - based query(r) - query(l-1)
            res[idx] = query(n) - query(idx);
            update(idx+1, 1);
        }
        return res;
    }
};
int mod = 1e9 + 7;
class FenwickTree{
    vector<int> bit;
    int size;
    public:
        FenwickTree(int n) {
            bit.resize(n+1, 0);
            size = n;
        }

        int query(int id) {
            int ans = 0;
            while(id > 0) {
                ans += bit[id];
                id -= (id & -id);
            }
            return ans;
        }

        void update(int id, int val) {
            while(id <= size) {
                bit[id] += val;
                id += (id & -id);
            }
        }
};
class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        int n = instructions.size();
        int max_val = *max_element(instructions.begin(), instructions.end());
        long long res = 0;
        int size = max_val+1;
        FenwickTree fen(size);
        for(auto &x : instructions) {
            long long left_sum = fen.query(x-1);
            long long right_sum = fen.query(size) - fen.query(x);
            res += min(left_sum, right_sum);
            fen.update(x, 1);
        }
        return res % mod;
    }
};
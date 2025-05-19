class FenwickTree{
    private:
        vector<int> bit;
        int N;
    public:
        FenwickTree(int n) {
            bit.resize(n+1,0);
            N = n+1;
        }

        int query(int id) {
            int ans = 0;
            while(id > 0) {
                ans = max(ans, bit[id]);
                id -= (id & -id);
            }
            return ans;
        }

        void update(int id, int val) {
            while(id < N) {
                bit[id] = max(bit[id], val);
                id += (id & -id);
            }
        }
};

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> res(n);
        int maxx = *max_element(obstacles.begin(), obstacles.end());
        FenwickTree fen(maxx);
        for(int i = 0;i < n;i++) {
            int idx = obstacles[i];
            //ascending so till that point
            int max_len = fen.query(idx) + 1;
            res[i] = max_len;
            fen.update(idx, max_len);
        }
        return res;
    }
};
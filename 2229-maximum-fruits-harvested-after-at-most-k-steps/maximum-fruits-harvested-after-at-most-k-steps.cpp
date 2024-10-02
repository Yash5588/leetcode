class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startpos, int k) {
        int size = fruits.back()[0]+1;
        vector<long long> left(400000,0);
        vector<long long> right(400000,0);
        unordered_map<long long,long long> mp;
        int n = fruits.size();
        for(int i = 0;i < n;i++) {
            mp[fruits[i][0]] = fruits[i][1];
        }
        for(int i = startpos-1;i >= 0;i--) {
            left[i] = left[i+1] + mp[i];
        }
        for(int i = startpos+1;i < size;i++) {
            right[i] = right[i-1] + mp[i];
        }

        long long ma = 0;
        long long steps = 1;
        for(int i = startpos-1;i >= 0;i--) {
            if(steps <= k) {
                int shift = startpos + (k-2*steps);
                if(k > 2*steps) {
                    ma = max(ma, left[i] + right[shift>size-1 ? size-1 : shift]);
                }
                else {
                    ma = max(ma, left[i]);
                }
            }
            else break;
            steps++;
        }
        steps = 1;
        for(int i = startpos+1;i < size;i++) {
            if(steps <= k) {
                int shift = startpos-(k-2*steps);
                if(k > 2*steps) {
                    ma = max(ma, right[i] + left[shift>0 ? shift : fruits.front()[0]]);
                }
                else {
                    ma = max(ma, right[i]);
                }
            }
            else break;
            steps++;
        }
        // return 0;
        return ma + mp[startpos];
    }
};
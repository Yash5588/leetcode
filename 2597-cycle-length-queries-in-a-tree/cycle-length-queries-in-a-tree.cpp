class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> res;
        for(auto &q : queries) {
            int small = min(q[0],q[1]);
            int large = max(q[0],q[1]);
            vector<int> larger_path;
            while(large >= 1) {
                larger_path.push_back(large);
                large >>= 1;
            }
            int ind = -1;
            int cnt = 0;
            while(small >= 1) {
                auto iter = find(larger_path.begin(),larger_path.end(),small);
                if(iter != larger_path.end()) {
                    ind = iter - larger_path.begin();
                    break;
                }
                small >>= 1;
                cnt++;
            }
            res.push_back(cnt + ind + 1);
        }
        return res;
    }
};
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        int m = queries.size();
        vector<int> res;
        vector<int> prefix_xor(n,0);
        prefix_xor[0] = arr[0];
        for(int i=1;i<n;i++) {
            prefix_xor[i] = prefix_xor[i-1] ^ arr[i];
        }
        for(auto &q : queries) {
            if(q[0] == 0) res.push_back(prefix_xor[q[1]]);
            else res.push_back(prefix_xor[q[1]] ^ prefix_xor[q[0] - 1]);
        }
        return res;
    }
};
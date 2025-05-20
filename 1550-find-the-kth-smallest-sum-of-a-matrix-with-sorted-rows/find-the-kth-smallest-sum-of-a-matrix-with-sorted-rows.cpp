class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        int sum = 0;
        for(int i = 0;i < m;i++) {
            sum += mat[i][0];
        }
        vector<int> v(m,0);
        using PIV = pair<int,vector<int>>;
        priority_queue<PIV, vector<PIV>, greater<PIV>> pq;
        pq.push({sum, v});
        int cnt = 0;
        set<PIV> se;
        se.insert({sum, v});
        while(!pq.empty() && cnt < k) {
            sum = pq.top().first;
            cout << sum << endl;
            vector<int> cols = pq.top().second;
            pq.pop();
            cnt++;
            for(int i = 0;i < m;i++) {
                int j = cols[i];
                if(j+1 < n) {
                    int new_sum = sum - mat[i][j] + mat[i][j+1];
                    cols[i]++;
                    if(se.find({new_sum, cols}) == se.end()) {
                        pq.push({new_sum, cols});
                        se.insert({new_sum, cols});
                    }
                    cols[i]--;
                }

            }
        }
        return sum;
    }
};
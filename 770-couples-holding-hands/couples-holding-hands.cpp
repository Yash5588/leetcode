class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        vector<int> indices(n,0);
        for(int i = 0;i < n;i++) {
            indices[row[i]] = i;
        }
        int cnt = 0;
        for(int i = 0;i < n;i += 2) {
            if(row[i] & 1) {
                if(row[i+1] != row[i] - 1) {
                    int first = row[i+1];
                    int second = row[i]-1;
                    int temp = indices[first];
                    indices[first] = indices[second];
                    indices[second] = temp;
                    row[indices[first]] = first;
                    row[indices[second]] = second;
                    cnt++;
                }
            }
            else {
                if(row[i+1] != row[i] + 1) {
                    int first = row[i+1];
                    int second = row[i]+1;
                    int temp = indices[first];
                    indices[first] = indices[second];
                    indices[second] = temp;
                    row[indices[first]] = first;
                    row[indices[second]] = second;
                    cnt++;
                }
            }
            // for(auto &x : row) cout << x << endl;
            // cout << endl;
        }
        return cnt;
    }
};
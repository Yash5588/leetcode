class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<int> que;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                que.push(matrix[i][j]);
                if(que.size() > k) que.pop();
            }
        }
        return que.top();
    }
};
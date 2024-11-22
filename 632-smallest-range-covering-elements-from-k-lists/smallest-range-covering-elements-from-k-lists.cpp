class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> que;
        int maxEle = INT_MIN;
        for(int i = 0;i < k;i++) {
            que.push({nums[i][0], i, 0});
            maxEle = max(maxEle, nums[i][0]);
        }
        int low = 0;
        int high = 1e6;
        while(true) {
            vector<int> minStatus = que.top();
            int minEle = minStatus[0];
            int listIndex = minStatus[1];
            int ind = minStatus[2];
            que.pop();
            if(maxEle - minEle < high - low) {
                low = minEle;
                high = maxEle;
            }
            int size = nums[listIndex].size();
            if(ind + 1 >= size) break;
            int nextEle = nums[listIndex][ind+1];
            que.push({nextEle, listIndex, ind+1});
            maxEle = max(maxEle, nextEle);
        }
        return {low,high};
    }
};
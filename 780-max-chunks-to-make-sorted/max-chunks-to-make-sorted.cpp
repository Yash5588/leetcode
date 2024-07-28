class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        stack<int> sta;
        for(int i=0;i<n;i++) {
            int ma = max(ma,arr[i]);
            while(!sta.empty() && sta.top() > arr[i]) {
                sta.pop();
            }
            sta.push(ma);
        }
        return sta.size();
    }
};
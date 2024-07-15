class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        int n = a.size();
        unordered_map<int,int> prevSum;
        prevSum[0] = 1;
        int count = 0;
        int sum = 0;
        for(int i=0;i<n;i++) {
            sum += a[i];
            count += prevSum[sum-k];
            prevSum[sum]++;
        }
        return count;
    }
};
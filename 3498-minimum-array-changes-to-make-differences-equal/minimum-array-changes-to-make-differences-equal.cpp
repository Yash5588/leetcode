class Solution {
public:
    int minChanges(vector<int>& a, int k) {
        int n = a.size();
        vector<int>  oneDiff(k+1,0);
        unordered_map<int,int> difCount;
        for(int i=0;i<n/2;i++) {
            difCount[abs(a[i]-a[n-i-1])]++;
            int left = max(a[i],a[n-i-1]);
            int right = k - min(a[i],a[n-i-1]);
            oneDiff[max(left,right)]++;
        }
        for(int i=k-1;i>=0;i--) {
            oneDiff[i] += oneDiff[i+1];
        }
        int ans = INT_MAX;
        for(auto &x : difCount) {
            int zeroOpp = x.second;
            int oneOpp = oneDiff[x.first] - x.second;
            int twoOpp = n/2 - oneOpp - zeroOpp;
            ans = min(ans, oneOpp + 2*twoOpp);
        }
        return ans;

    }
};
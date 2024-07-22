class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        int n = a.size();
        vector<pair<int,int>> pro(n+2);
        pro[0] = pro[n+1] = {1,1};
        for(int i=1;i<=n;i++) pro[i].first = pro[i-1].first * a[i-1];
        for(int i=n;i>0;i--) pro[i].second = pro[i+1].second * a[i-1];
        vector<int> ans(n);
        for(int i=1;i<=n;i++) {
            ans[i-1] = pro[i-1].first * pro[i+1].second;
        }
        return ans;
    }
};
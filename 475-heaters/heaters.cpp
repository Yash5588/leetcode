class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int ans = 0;
        sort(heaters.begin(),heaters.end());
        int n = houses.size();
        for(int i=0;i<n;i++) {
            auto iter = lower_bound(heaters.begin(),heaters.end(),houses[i]);
            int dist1 = INT_MAX,dist2 = INT_MAX;
            if(iter != heaters.end()) {
                dist1 = *iter - houses[i];
            }
            if(iter != heaters.begin()) {
                dist2 = houses[i] - *(--iter);
            }
            ans = max(ans,min(dist1,dist2));
        }
        return ans;
    }
};
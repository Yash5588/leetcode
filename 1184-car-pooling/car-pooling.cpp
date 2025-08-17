class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> mp;
        for(auto trip: trips) {
            mp[trip[1]] += trip[0];
            mp[trip[2]] -= trip[0];
        }
        int members = 0;
        for(auto &[loc,num] : mp) {
            members += num;
            if(members > capacity) return false;
        }
        return true;
    }
};